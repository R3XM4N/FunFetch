#include "report.hpp"

void report::findOs(){
    std::vector<std::string> tags = {"pretty_name", "id", "build_id"};
    std::ifstream file_reader;
    std::string buffer_string;
    file_reader = std::ifstream("/etc/os-release");
    
    while (getline(file_reader, buffer_string))
    {
        for (std::string tag : tags)
        {
            if (toLowerString(buffer_string).contains(tag) && tolower(buffer_string[0]) == tag[0])
            {
                cutBeforeChar(buffer_string, '=');
                trimChar(buffer_string, '"');
                if (tag == "pretty_name")
                {
                    this->system.name = buffer_string;
                    tags.erase(std::remove(tags.begin(), tags.end(), tag), tags.end());
                }
                else if (tag == "id"){
                    this->system.id = buffer_string;
                    tags.erase(std::remove(tags.begin(), tags.end(), tag), tags.end());
                }
                else if (tag == "build_id"){
                    this->system.type = buffer_string;
                    tags.erase(std::remove(tags.begin(), tags.end(), tag), tags.end());
                }
                //std::cout << buffer_string << std::endl;
            }
            if (tags.empty()) {break;}
        }
        if (tags.empty()) {break;}
    }
}

void report::steal(){
    this->findOs();
    this->getPackages();
    this->getCpu();
}


void report::getCpu(){
    std::vector<std::string> tags = {"vendor_id", "model name", "siblings", "cpu cores"};
    std::string buffer_string;
    std::ifstream file_reader("/proc/cpuinfo");

    while (getline(file_reader, buffer_string))
    {
        for (std::string tag : tags)
        {
            if (toLowerString(buffer_string).contains(tag) && tolower(buffer_string[0]) == tag[0])
            {
                cutBeforeChar(buffer_string, ':');
                trimChar(buffer_string, ' ');
                if (tag == "cpu cores")
                {
                    this->cpu_info.cores = stoi(buffer_string);
                    tags.erase(std::remove(tags.begin(), tags.end(), tag), tags.end());
                }
                else if (tag == "vendor_id"){
                    this->cpu_info.vendor_id = buffer_string;
                    tags.erase(std::remove(tags.begin(), tags.end(), tag), tags.end());
                }
                else if (tag == "model name"){
                    this->cpu_info.model_name = buffer_string;
                    tags.erase(std::remove(tags.begin(), tags.end(), tag), tags.end());
                }
                else if (tag == "siblings"){
                    this->cpu_info.threads = stoi(buffer_string);
                    tags.erase(std::remove(tags.begin(), tags.end(), tag), tags.end());
                }
                //std::cout << buffer_string << std::endl;
            }
            if (tags.empty()) {break;}
        }
        if (tags.empty()) {break;}
    }
}

//HALF ASSED SOLUTION
bool command_exists(const std::string &name) {
    static const std::vector<std::string> prefixes = {
        "/usr/bin/", "/bin/", "/usr/local/bin/"
    };
    
    for (auto &p : prefixes) {
        auto full = p + name;
        if (access(full.c_str(), X_OK) == 0)
        return true;
    }
    return false;
}

void report::getPackages(){
    std::vector<std::pair<std::string, std::string>> managers = 
    {
        {"pacman", "pacman -Q"},
        {"dpkg", "dpkg-query -f '${binary:Package}\\n' -W"},
        {"rpm", "rpm -qa"},
        {"apk", "apk info"},
        {"xbps", "xbps-query -l"},
        {"flatpak", "flatpak list"},
        {"snap", "snap list | tail -n +2"}
    };
    
    for (const auto& [name, cmd] : managers)
    {
        if (!command_exists(name))continue;
        
        //std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen((cmd + " 2>/dev/null").c_str(), "r"), pclose);
        if (!pipe) continue;
        
        size_t count = 0;
        std::array<char, 256> buffer;
        while (fgets(buffer.data(), buffer.size(), pipe.get())) ++count;
        
        if (name == "flatpak")
        this->flatpak_package_count = count;
        else if (name == "snap")
        this->snap_package_count = count;
        else
        this->os_package_count += count;
    }
    this->os_package_count += 1;
}

void report::printConsole(){
    std::cout << "OS  : " << this->system.name << "\n";
    std::cout << "ID  : " << this->system.id << "\n";
    std::cout << "Type: " << this->system.type << "\n";
    std::cout << "\n";
    
    std::cout << "Packages: " << os_package_count << "\n";
    if (flatpak_package_count > 0)
    {
        std::cout << "Flatpak: " << flatpak_package_count << "\n";
    }
    if (snap_package_count > 0)
    {
        std::cout << "Snap: " << snap_package_count << "\n";
    }
    struct sysinfo info;
    if (sysinfo(&info) == 0)
    {
        long uptime = info.uptime;
        short int upTime[4] = {
            static_cast<short int>(uptime % 60), 
            static_cast<short int>((uptime/60) % 60), 
            static_cast<short int>(((uptime/60)/60) % 24), 
            static_cast<short int>(((uptime/60)/60)/24)
        };
        if (upTime[3] < 1)
        {
            std::cout << "Uptime: " << upTime[2] << ":" << upTime[1] << ":" << upTime[0] << " (" << uptime << ")" << "\n";
        }
        else if (upTime[2] < 1)
        {
            std::cout << "Uptime: "  << ":" << upTime[1] << ":" << upTime[0] << " (" << uptime << ")" << "\n";
        }
        else{
            std::cout << "Uptime: " << upTime[3] << ":" << upTime[2] << ":" << upTime[1] << ":" << upTime[0] << " (" << uptime << ")" << "\n";
        }
    }
    
    std::cout << "\n";
    std::cout << "--CPU--\n";
    std::cout << "Vendor : " << this->cpu_info.vendor_id << "\n";
    std::cout << "Model  : " << this->cpu_info.model_name << "\n";
    std::cout << "Cores  : " << this->cpu_info.cores << "\n";
    std::cout << "Threads: " << this->cpu_info.threads << "\n";
    std::cout << "\n";
}
report::report(/* args */)
{
}

report::~report()
{
}
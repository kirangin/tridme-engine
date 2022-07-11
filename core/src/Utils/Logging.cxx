#include <Utils/Logging.h>

void Tridme::LOG(int type, std::string s) {
  /* Get Time */
  std::time_t time = std::time(0);
  std::tm* tm      = std::localtime(&time);

  std::string _type;

  switch (type) {
    case SUCCESS: _type = "SUCCESS"; break;
    case WARNING: _type = "WARNING"; break;
    case ERROR: _type = "ERROR"; break;
    case INFO: _type = "INFO"; break;
  }

  /**
   * Example Output format: 
   * [18:29:22, ERROR]: Hello World
   **/
  std::cout << "["<< tm->tm_hour << ":" << tm->tm_min << ":" << tm->tm_sec << ", " 
            << _type << "]: " << s << std::endl;	
}
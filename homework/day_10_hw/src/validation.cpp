#include <cctype>
#include <string>

namespace validation{
    bool is_valid_password(std::string password){
        bool has_upper = false;
        bool has_nonalphanum = false;

        for (char c : password){
            if (std::isupper(c)){has_upper = true;}
            if (!std::isalnum(c)){has_nonalphanum = true;}
        }

        return (has_upper && has_nonalphanum && (password.length() >= 8));
    }
}

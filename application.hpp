#include <string>

class Application{
    public:
    Application() = default;
    void Exec();
    void Quit();

    private:
    bool running{false};
    enum Selection{ QUIT, OPT1, OPT2 };

    void PrintMenu() const;
    Selection GetUserInput();
    Selection StrToSelection(const std::string& s) const;
};
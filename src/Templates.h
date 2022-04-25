
namespace training::geometry 
{
    template<typename T>
    void Show(const T& t)
    {
        std::cout << t << std::endl;
    }
    
    template<typename T, class... Args>
    void Show(const T& t, const Args&... args)
    {
        Show(t);
        Show(args...);
    }

}

#include <iostream>

// ************************************************

enum class TimeUnit
{
    SECONDS,
    MINUTES,
    HOURS,
    DAYS,
};

// ************************************************

class Duration
{
private:
    unsigned long long seconds;

public:
    constexpr Duration() : seconds{} {}
    constexpr Duration(unsigned long long value, TimeUnit unit = TimeUnit::SECONDS)
        : seconds{
              unit == TimeUnit::SECONDS
                  ? value
                  : (unit == TimeUnit::MINUTES
                         ? 60 * value
                         : (unit == TimeUnit::HOURS
                                ? 3600 * value
                                : (unit == TimeUnit::DAYS
                                       ? 24 * 3600 * value
                                       : -1)))} {}

    constexpr unsigned long long getSeconds() const { return seconds; }

    friend std::ostream &operator<<(std::ostream &out, Duration duration);

    constexpr Duration operator+(Duration other) { return Duration(seconds + other.seconds); }
};

// ************************************************

constexpr Duration operator"" _s(unsigned long long value) { return Duration{value, TimeUnit::SECONDS}; }
constexpr Duration operator"" _min(unsigned long long value) { return Duration{value, TimeUnit::MINUTES}; }
constexpr Duration operator"" _h(unsigned long long value) { return Duration{value, TimeUnit::HOURS}; }
constexpr Duration operator"" _d(unsigned long long value) { return Duration{value, TimeUnit::DAYS}; }

std::ostream &operator<<(std::ostream &out, Duration duration)
{
    out << duration.seconds << " [s]";
    return out;
}

// ************************************************

int main()
{
    Duration shorterTime{3_s + 1_min};
    Duration longerTime{shorterTime + 24_h + 2_d + 5_h};

    std::cout << "shorterTime: " << shorterTime << std::endl; // 63 [s]
    std::cout << "longerTime: " << longerTime << std::endl;   // 277263 [s]

    return 0;
}

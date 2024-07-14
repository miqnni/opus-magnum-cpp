#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <map>
#include <algorithm> // std::reverse
#include <iterator>  // std::reverse
#include <ctime>     // localtime(), asctime()

using MaskType = unsigned short int;

constexpr MaskType MAX_MASK{0xff};
constexpr int MONTH_COUNT{12};
constexpr int FIRST_MONTH_ID{0};
constexpr int SETTINGS_COUNT{4};

static_assert(MAX_MASK > 0 && MAX_MASK <= 0xff);
static_assert(MONTH_COUNT == 12);

enum class Month
{
    January = FIRST_MONTH_ID,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
}; // potential use of static_cast (to int)

enum class SettingsFlags : MaskType
{
    DISPLAY_DAY_OF_WEEK_HEADER_F = 0x1,
    DISPLAY_CURRENT_DATE_F = 0x2,
    DISPLAY_SETTINGS_SIZE_F = 0x4,
    DISPLAY_SETTINGS_ALIGNMENT_F = 0x8,
};

std::map<Month, std::string> monthNames = {
    {Month::January, "January"},
    {Month::February, "February"},
    {Month::March, "March"},
    {Month::April, "April"},
    {Month::May, "May"},
    {Month::June, "June"},
    {Month::July, "July"},
    {Month::August, "August"},
    {Month::September, "September"},
    {Month::October, "October"},
    {Month::November, "November"},
    {Month::December, "December"},
};

std::map<Month, const int> monthDays = {
    {Month::January, 31},
    {Month::February, 28}, // BEWARE OF LEAP YEARS
    {Month::March, 31},
    {Month::April, 30},
    {Month::May, 31},
    {Month::June, 30},
    {Month::July, 31},
    {Month::August, 31},
    {Month::September, 30},
    {Month::October, 31},
    {Month::November, 30},
    {Month::December, 31},
};

Month months[MONTH_COUNT] = {
    Month::January,
    Month::February,
    Month::March,
    Month::April,
    Month::May,
    Month::June,
    Month::July,
    Month::August,
    Month::September,
    Month::October,
    Month::November,
    Month::December,
};

// A parent class (that contains
// a virtual method) for
// CalendarDisplay.
// Created solely for checking how
// `dynamic_cast` works.
class AbstractCalendar
{
public:
    virtual void printCalendar(int year) = 0;
};

class CalendarDisplay : public AbstractCalendar
{
private:
    MaskType settings;
    MaskType monthsToDisplay;
    // Months to display:
    // jfmamjjasond
    // 010101010110 -- max. 2^12 - 1

    void printCurrentTime()
    {
        time_t currentTime;

        // The two versions (A, B) below show both ways
        // we can use time() function from ctime library
        // to store the current time in time_t variable.
        // Version A
        // currentTime = time(NULL);
        // Version B
        time(&currentTime);

        // Converting currentTime to an object of
        // structure `tm`, where we can access
        // hours, minutes and seconds using
        // `tm_hour`, `tm_min`, `tm_sec`
        // respectively.
        tm *currentTimeLocal = localtime(&currentTime);

        // Hex values of hh:mm:ss
        // std::cout << std::endl
        //           << "Current date and time: " << currentTimeLocal->tm_hour << ":" << currentTimeLocal->tm_min << ":" << currentTimeLocal->tm_sec << std::endl;

        std::string currentTimeReadable = asctime(currentTimeLocal);
        std::cout << std::endl
                  << "Current date and time: " << std::endl
                  << currentTimeReadable << std::endl;
    }

public:
    CalendarDisplay()
        : settings(MAX_MASK), monthsToDisplay(MAX_MASK) {}

    CalendarDisplay(MaskType customMaskSettings, MaskType customMaskMonths)
        : settings(customMaskSettings), monthsToDisplay(customMaskMonths) {}

    CalendarDisplay(
        bool displayDayOfWeekHeader,
        bool displayCurrentDate,
        bool displaySettingsSize,
        bool displaySettingsAlignment,
        std::string selectedMonths)
    {
        MaskType tmpSettingsMask{0};
        MaskType tmpMonthMask{0};
        try
        {
            // SETTINGS MASK

            bool inputSettings[SETTINGS_COUNT] = {
                // flag values
                displayDayOfWeekHeader,   // 0x1
                displayCurrentDate,       // 0x2
                displaySettingsSize,      // 0x4
                displaySettingsAlignment, // 0x8
            };

            // We are going to use bitshift to build a settings mask based on
            // bool arguments. We assign every bit of the mask on the right,
            // then push it to the left. Reversing the array enables us
            // to begin assigning bits by assissing the bool argument
            // that has the greatest corresponding flag value.
            std::reverse(std::begin(inputSettings), std::end(inputSettings));

            for (bool includeCurrOption : inputSettings)
            {
                tmpSettingsMask <<= 1; // First iteration => nothing happens
                tmpSettingsMask |= static_cast<MaskType>(includeCurrOption);
            }

            settings = tmpSettingsMask;

            // MONTHS MASK

            for (char currMonthOption : selectedMonths)
            {
                bool includeCurrMonth;
                switch (currMonthOption)
                {
                case 'o':
                case 'O':
                    includeCurrMonth = true;
                    break;
                case 'x':
                case 'X':
                    includeCurrMonth = false;
                    break;
                default:
                    throw std::runtime_error("Incorrect character in your month input.");
                }

                tmpMonthMask <<= 1; // First iteration => nothing happens
                tmpMonthMask |= static_cast<MaskType>(includeCurrMonth);
            }

            monthsToDisplay = tmpMonthMask;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        settings = tmpSettingsMask;
        monthsToDisplay = tmpMonthMask;
    }

    void printCalendar(int year)
    {
        // std::cout << "CALENDAR" << std::endl;
        // std::cout << "Settings: " << std::hex << settings << std::endl;
        // std::cout << "Months: " << std::hex << monthsToDisplay << std::endl;

        std::cout << "Calendar - " << year << std::endl
                  << std::endl
                  << std::endl;

        int monthsChecked;
        MaskType currMonthBit;
        for (monthsChecked = 0, currMonthBit = 1 << (MONTH_COUNT - 1); currMonthBit > 0; monthsChecked++, currMonthBit >>= 1)
        {
            if (currMonthBit & monthsToDisplay)
            {
                std::cout << std::endl
                          << "  ------------" << monthNames[months[monthsChecked]] << "------------" << std::endl;

                if (settings & static_cast<MaskType>(SettingsFlags::DISPLAY_DAY_OF_WEEK_HEADER_F))
                    std::cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << std::endl;
            }
        }

        // TODO: ...displaying the calendar...

        if (settings & static_cast<MaskType>(SettingsFlags::DISPLAY_CURRENT_DATE_F))
            printCurrentTime();

        if (settings & static_cast<MaskType>(SettingsFlags::DISPLAY_SETTINGS_SIZE_F))
        {
            size_t calendarDisplaySizeInBytes = sizeof(CalendarDisplay);
            std::cout << std::endl
                      << "[DISPLAY SIZE] CalendarDisplay objects' size in bytes: " << std::endl
                      << calendarDisplaySizeInBytes << std::endl;
        }

        if (settings & static_cast<MaskType>(SettingsFlags::DISPLAY_SETTINGS_ALIGNMENT_F))
        {
            int calendarDisplayAddressIsMultipleOf = alignof(CalendarDisplay);
            std::cout << std::endl
                      << "[DISPLAY ADDRESS ALIGNMENT] CalendarDisplay objects' address is a multiple of: " << std::endl
                      << calendarDisplayAddressIsMultipleOf << std::endl;
        }
    }
};

// int dayOfWeek(int day, int month, int year)
// {
//     return -1;
// }

int main()
{
    try
    {
        // Playground for testing const_cast, dynamic_cast and reinterpret_cast
        const bool displayDayOfWeekHeader{false};
        const bool displayCurrentDate{false};
        const bool displaySettingsSize{false};
        const bool displaySettingsAlignment{false};
        // jfmamjjasond
        // oxxoxxooxooo <-- example user input
        // o -- display month
        // x -- skip month

        bool *settingsPointers[SETTINGS_COUNT] = {
            const_cast<bool *>(&displayDayOfWeekHeader),
            const_cast<bool *>(&displayCurrentDate),
            const_cast<bool *>(&displaySettingsSize),
            const_cast<bool *>(&displaySettingsAlignment),
        };

        std::string questionBank[SETTINGS_COUNT]{
            "Do you want to display the days of the week in the calendar?",
            "Do you want to display the current date below the calendar?",
            "Do you want to display the size of CalendarDisplay class objects?",
            "Do you want to display the address alignment of CalendarDisplay class objects?",
        };

        int qNum{0};
        std::cout << "Questions: ";
        while (qNum < SETTINGS_COUNT)
        {
            int displayQNum;
            displayQNum = ++qNum;
            std::cout << "Q" << displayQNum << (qNum != SETTINGS_COUNT ? ' ' : '\n');
        }

        char userChoice;
        int currQuestionSettingsIdx{0};
        while (currQuestionSettingsIdx < SETTINGS_COUNT)
        {
            int idxForBoth;
            idxForBoth = currQuestionSettingsIdx++;
            std::cout << questionBank[idxForBoth] << " (y/n):";
            std::cin >> userChoice;
            *settingsPointers[idxForBoth] = tolower(userChoice) == 'y';
        };

        // [START> Use of reinterpret_cast in both ways purely for fun (totally impractical)
        void *onlyAddresses[SETTINGS_COUNT];
        int onlyAddressesIdx{0};
        for (bool *boolAddr : settingsPointers)
        {
            onlyAddresses[onlyAddressesIdx++] = reinterpret_cast<void *>(boolAddr);
        }

        bool finalArgs[SETTINGS_COUNT];
        int finalArgsIdx{0};

        for (void *voidAddr : onlyAddresses)
        {
            finalArgs[finalArgsIdx++] = *(reinterpret_cast<bool *>(voidAddr));
        }
        // reinterpret_cast <END]

        std::cout << R"(

============================================================
SELECT MONTHS TO BE DISPLAYED
You will see a string that consists of the
first letter of every month (in lowercase),
from January ('j') to December ('d').
Below each letter type one of the following:
'o' to display the month above
'x' to skip the month above

EXAMPLE
v  v  vv vvv <-- which months have been selected
jfmamjjasond <-- first letters of month names (lowercase)
oxxoxxooxooo <-- example user input
o -- display month
x -- skip month
selected months: January, April, June,
                 August, October, November,
                 December.

(Press any key to continue.)
============================================================
)";

        system("pause");
        std::cout << R"(
YOUR INPUT
jfmamjjasond
)";

        std::string monthSelection;

        // Get rid of every line from the standard input stream
        // before calling the getline() function
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(std::cin, monthSelection);

        // DEBUG start
        // std::cout << "Your selection: " << monthSelection << "_OK!" << std::endl;
        // DEBUG end

        if (monthSelection.length() != MONTH_COUNT)
            throw std::runtime_error("Your input has an incorrect number of characters.");

        CalendarDisplay calendarDisplay(
            finalArgs[0],
            finalArgs[1],
            finalArgs[2],
            finalArgs[3],
            monthSelection);

        int userYear;
        std::cout << "Year (to be displayed by the calendar): ";
        std::cin >> userYear;

        if (userYear <= 0)
            throw std::runtime_error("The year must be a positive number.");

        calendarDisplay.printCalendar(userYear);

        // Use of dynamic_cast purely for fun.
        std::cout << std::endl
                  << "Address of the used CalendarDisplay class object: " << dynamic_cast<AbstractCalendar *>(&calendarDisplay) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

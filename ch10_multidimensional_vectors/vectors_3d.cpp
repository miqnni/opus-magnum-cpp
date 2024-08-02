#include <iostream>
#include <vector>
#include <iomanip> // setw

using TheaterRow = std::vector<std::string>;
using TheaterFloor = std::vector<TheaterRow>;
using TheaterAuditorium = std::vector<TheaterFloor>;

const std::string availableSeatText{"(available)"};

void reservedSeats(TheaterAuditorium auditorium);
void displayReservations(TheaterAuditorium auditorium);
inline TheaterAuditorium createTheater(unsigned int floorCount, unsigned int rowsInAFloorCount, unsigned int seatsInARowCount)
{
    TheaterAuditorium createdTheater(
        floorCount,
        TheaterFloor(
            rowsInAFloorCount,
            TheaterRow(
                seatsInARowCount,
                availableSeatText)

                ));
    return createdTheater;
}
TheaterAuditorium createTheaterFromDescription(std::vector<std::vector<int>> theaterDescription);

// ************************************************

int main()
{
    std::vector<std::vector<int>> sampleDescription{
        {20, 20, 18, 17, 21, 5, 4, 27, 6, 17}, // Floor 0
        {10, 11, 12, 12, 11, 10},              // Floor 1
    };

    // TheaterAuditorium sampleTheater{createTheater(2, 10, 25)};
    TheaterAuditorium sampleTheater{createTheaterFromDescription(sampleDescription)};

    std::cout << sampleTheater[1][5][6] << std::endl;

    sampleTheater[0][1][12] = "Mieszko Pierwszy";
    sampleTheater[0][1][13] = "Boleslaw Chrobry";
    sampleTheater[0][2][13] = "Mieszko Drugi";
    sampleTheater[1][5][6] = "Boleslaw Smialy";
    sampleTheater[1][5][7] = "Boleslaw Krzywousty";
    sampleTheater[0][7][23] = "Eminem";

    std::cout << sampleTheater[1][5][6] << std::endl;

    reservedSeats(sampleTheater);
    std::cout << std::endl;
    displayReservations(sampleTheater);
    return 0;
}

// ************************************************

// OLD
// void reservedSeats(TheaterAuditorium auditorium)
// {
//     std::cout << "Reserved seats" << std::endl;
//     for (int floorNumber{}; floorNumber < auditorium.size(); floorNumber++)
//     {
//         std::cout << "Floor " << floorNumber << std::endl;
//         for (int rowNumber{}; rowNumber < auditorium[floorNumber].size(); rowNumber++)
//         {
//             for (int seatNumber{}; seatNumber < auditorium[floorNumber][rowNumber].size(); seatNumber++)
//             {
//                 std::cout << "|"
//                           << (auditorium[floorNumber][rowNumber][seatNumber] == availableSeatText ? "." : "X");
//             }
//             std::cout << "|" << std::endl;
//         }
//     }
// }

// NEW -- Used ranged `for` loop where it was advisable.
void reservedSeats(TheaterAuditorium auditorium)
{
    std::cout << "Reserved seats" << std::endl;
    for (int floorNumber{}; floorNumber < auditorium.size(); floorNumber++)
    {
        std::cout << "Floor " << floorNumber << std::endl;
        for (const auto &currentRow : auditorium[floorNumber])
        {
            for (const auto &currentSeat : currentRow)
            {
                std::cout << "|"
                          << (currentSeat == availableSeatText ? "." : "X");
            }
            std::cout << "|" << std::endl;
        }
    }
}

// ************************************************

void displayReservations(TheaterAuditorium auditorium)
{
    std::cout << "Details of reservations" << std::endl;
    std::cout << "The viewers of today's play are as follows:" << std::endl;

    int viewerCount{};

    for (int floorNumber{}; floorNumber < auditorium.size(); floorNumber++)
    {
        for (int rowNumber{}; rowNumber < auditorium[floorNumber].size(); rowNumber++)
        {
            for (int seatNumber{}; seatNumber < auditorium[floorNumber][rowNumber].size(); seatNumber++)
            {
                if (auditorium[floorNumber][rowNumber][seatNumber] != availableSeatText)
                {
                    viewerCount++;
                    std::cout << "Mr./Ms. " << std::setw(32) << auditorium[floorNumber][rowNumber][seatNumber] << " -- " << "floor: " << floorNumber << ", row: " << rowNumber << ", seat: " << seatNumber << std::endl;
                }
            }
        }
    }
    std::cout << "Total: " << viewerCount << " viewers." << std::endl;
}

// ************************************************

TheaterAuditorium createTheaterFromDescription(std::vector<std::vector<int>> theaterDescription)
{
    TheaterAuditorium createdTheater(theaterDescription.size());
    for (int currentFloorNumber{}; currentFloorNumber < theaterDescription.size(); currentFloorNumber++)
    {
        unsigned int rowsInCurrentFloor{theaterDescription[currentFloorNumber].size()};
        createdTheater[currentFloorNumber].resize(rowsInCurrentFloor);

        for (int currentRowNumber{}; currentRowNumber < rowsInCurrentFloor; currentRowNumber++)
        {
            int seatsInCurrentRow{theaterDescription[currentFloorNumber][currentRowNumber]};
            createdTheater[currentFloorNumber][currentRowNumber].resize(seatsInCurrentRow);

            for (auto &currentSeat : createdTheater[currentFloorNumber][currentRowNumber])
            {
                currentSeat = availableSeatText;
            }
        }
    }

    return createdTheater;
}

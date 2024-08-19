#include <iostream>
#include <cstring>
#include <string>

// ************************************************

class Array2D
{
private:
    static constexpr int MAX_COLS{30};
    double (*data)[MAX_COLS];
    size_t actualRows;
    size_t actualCols;

public:
    Array2D() : data{nullptr}, actualRows{0}, actualCols{0}
    {
        fillWithValue(0);
    }

    Array2D(size_t rows, size_t cols)
        : data{new double[rows][MAX_COLS]}, actualRows{rows}, actualCols{cols}
    {
        if (actualCols > MAX_COLS)
        {
            std::string errorMessage{"The maximum number of columns is " + std::to_string(MAX_COLS)};
            throw std::out_of_range(errorMessage);
        }
        fillWithValue(0);
    }

    ~Array2D() { delete[] data; }

    Array2D(Array2D &other)
        : data{new double[other.actualRows][MAX_COLS]},
          actualRows{other.actualRows},
          actualCols{other.actualCols}
    {
        std::memcpy(data, other.data, sizeof(double[MAX_COLS]) * other.actualRows);
    }

    Array2D(Array2D &&other) noexcept
        : data{other.data},
          actualRows{other.actualRows},
          actualCols{other.actualCols}
    {
        other.data = nullptr;
        // Waste of time
        // other.actualRows = 0;
        // other.actualCols = 0;
    }

    Array2D &operator=(Array2D &other);

    Array2D &operator=(Array2D &&other) noexcept;

    double &operator()(size_t rowIndex, size_t colIndex);

    friend std::ostream &operator<<(std::ostream &out, Array2D array2d);

private:
    Array2D &fillWithValue(double value = 0);
};

// ************************************************

Array2D &Array2D::operator=(Array2D &other)
{
    if (this == &other)
        return *this;

    delete[] data;

    data = new double[other.actualRows][MAX_COLS];
    std::memcpy(data, other.data, sizeof(double[MAX_COLS]) * other.actualRows);
    actualRows = other.actualRows;
    actualCols = other.actualCols;

    return *this;
}

Array2D &Array2D::operator=(Array2D &&other) noexcept
{
    if (this == &other)
        return *this;

    delete[] data;

    data = other.data;
    actualRows = other.actualRows;
    actualCols = other.actualCols;

    other.data = nullptr;
    // Waste of time
    // other.actualRows = 0;
    // other.actualCols = 0;

    return *this;
}

double &Array2D::operator()(size_t rowIndex, size_t colIndex)
{
    try
    {
        if (rowIndex > actualRows)
            throw std::out_of_range("The row index " + std::to_string(rowIndex) + " is too big. Expected [0, " + std::to_string(actualRows) + ").");
        if (colIndex > actualCols)
            throw std::out_of_range("The column index " + std::to_string(colIndex) + " is too big. Expected [0, " + std::to_string(actualCols) + ").");

        return data[rowIndex][colIndex];
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
        return data[0][0];
    }
}

std::ostream &operator<<(std::ostream &out, Array2D array2d)
{
    for (int rowIndex{}; rowIndex < array2d.actualRows; rowIndex++)
    {
        for (const auto &el : array2d.data[rowIndex])
            out << el << " ";
        out << "\n";
    }
    return out;
}

Array2D &Array2D::fillWithValue(double value)
{
    for (int rowIndex{}; rowIndex < actualRows; rowIndex++)
    {
        for (auto &el : data[rowIndex])
            el = value;
    }
    return *this;
}

// ************************************************

int main()
{
    Array2D testArray(8, 10);
    testArray(6, 3) = 0.33;

    Array2D testArrayCopy = testArray;
    Array2D testArrayMove = std::move(testArrayCopy);

    std::cout << testArrayMove << std::endl;

    // std::cout << testArray(10, 5) << std::endl;

    return 0;
}

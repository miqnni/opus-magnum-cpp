#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath> // abs()
// #include <mutex> // TODO: make mutex work on Windows
// #include <thread>

namespace my_constants
{
    // The same as:
    // constexpr unsigned short MAX_POINTS = 3;
    // etc.
    enum : unsigned short
    {
        MAX_POINTS = 3,
        POINTS_TO_PASS = MAX_POINTS - (MAX_POINTS / 2),
        PASS_THRESHOLD = POINTS_TO_PASS,
    };
}

// The intialization with 0 is not needed here, because the value is global
// and it would be automatically initialized with type-specific 0.
volatile int user_pts;

// std::mutex mtx;

// void incPoints()
// {
//     mtx.lock();
//     user_pts++;
//     mtx.unlock();
// }

// int getPoints()
// {
//     int curr_points;
//     mtx.lock();
//     curr_points = user_pts;
//     mtx.unlock();
//     return curr_points;
// }

using Dist = long double;
using Area = long double;
using Precision = long double;

constexpr auto STARTING_QUESTION_NUMBER{0uL};
auto starting_question_number_not_const{STARTING_QUESTION_NUMBER};
using Q_number_type = decltype(starting_question_number_not_const);

namespace my_constants
{
    constexpr double PI_VALUE{3.1415926535897};
    constexpr long double EPSILON{1e-2};
    constexpr int MAX_DIST{100};
}

enum class QuestionStatus
{
    NotAnswered = -1,
    Incorrect,
    Correct,
};

enum class ShapeInQuestion
{
    Rectangle,
    Triangle,
    Circle,
};

class Shape
{
public:
    Shape() {}
    virtual Area calculateArea() = 0; // Pure virtual function => Shape is an abstract class.
};

class Rectangle : public Shape
{
private:
    Dist width;
    Dist height;

public:
    Rectangle(Dist width, Dist height)
        : width(width), height(height) {}

    Area calculateArea() override
    {
        return width * height;
    }

    friend std::ostream &operator<<(std::ostream &os, const Rectangle &rectangle);
};

std::ostream &operator<<(std::ostream &os, const Rectangle &rectangle)
{
    os << "Rectangle\n\t- Width: " << rectangle.width << "\n\t- Height: " << rectangle.height;
    return os;
}

class RightAngledTriangle : public Shape
{
private:
    Dist cathetus_a;
    Dist cathetus_b;
    Dist hypotenuse;

    Dist pythagoras()
    {
        return sqrt(cathetus_a * cathetus_a + cathetus_b * cathetus_b);
    }

public:
    RightAngledTriangle(Dist cathetus_a, Dist cathetus_b)
        : cathetus_a(cathetus_a), cathetus_b(cathetus_b), hypotenuse(pythagoras())
    {
    }

    Area calculateArea() override
    {
        return 0.5 * cathetus_a * cathetus_b;
    }

    friend std::ostream &operator<<(std::ostream &os, const RightAngledTriangle &triangle);
};

std::ostream &operator<<(std::ostream &os, const RightAngledTriangle &triangle)
{
    os << "Right angled triangle\n\t- Cathetus \"a\": " << triangle.cathetus_a << "\n\t- Cathetus \"b\": " << triangle.cathetus_b;
    return os;
}

class Circle : public Shape
{
private:
    Dist radius;

public:
    Circle(Dist radius) : radius(radius) {}

    Area calculateArea() override
    {
        return my_constants::PI_VALUE * radius * radius;
    }

    friend std::ostream &operator<<(std::ostream &os, const Circle &circle);
};

std::ostream &operator<<(std::ostream &os, const Circle &circle)
{
    os << "Circle\n\t- Radius: " << circle.radius;
    return os;
}

class ShapeAreaQuestion
{
public:
    static Q_number_type question_count;

private:
    Q_number_type question_number;
    // Shape shape;
    Area expected_area;
    QuestionStatus status;
    Precision precision;

    // TODO: improve the code with polymorphism
    ShapeInQuestion shape_type;
    Rectangle shape_r;
    RightAngledTriangle shape_tr;
    Circle shape_c;

    bool
    isAnswerCorrect(Area user_area)
    {
        return abs(expected_area - user_area) < precision;
    }

public:
    // TODO: fix polymorphism, when you actually learn it.
    // // Delegating constructor
    // ShapeAreaQuestion(Shape shape)
    //     : ShapeAreaQuestion(shape, my_constants::EPSILON)
    // {
    // }

    // ShapeAreaQuestion(Shape shape, Precision precision)
    //     : question_number(question_count++),
    //       //   shape(shape),
    //       expected_area(shape.calculateArea()),
    //       status(QuestionStatus::NotAnswered),
    //       precision(precision)
    // {
    // }

    // Temporary spaghetti code
    ShapeAreaQuestion(Rectangle rectangle)
        : question_number(question_count++),
          expected_area(rectangle.calculateArea()),
          status(QuestionStatus::NotAnswered),
          precision(my_constants::EPSILON),
          shape_type(ShapeInQuestion::Rectangle),
          shape_r(rectangle),
          shape_tr(RightAngledTriangle(0, 0)),
          shape_c(Circle(0))
    {
    }
    ShapeAreaQuestion(RightAngledTriangle triangle)
        : question_number(question_count++),
          expected_area(triangle.calculateArea()),
          status(QuestionStatus::NotAnswered),
          precision(my_constants::EPSILON),
          shape_type(ShapeInQuestion::Triangle),
          shape_r(Rectangle(0, 0)),
          shape_tr(triangle),
          shape_c(Circle(0))
    {
    }
    ShapeAreaQuestion(Circle circle)
        : question_number(question_count++),
          expected_area(circle.calculateArea()),
          status(QuestionStatus::NotAnswered),
          precision(my_constants::EPSILON),
          shape_type(ShapeInQuestion::Circle),
          shape_r(Rectangle(0, 0)),
          shape_tr(RightAngledTriangle(0, 0)),
          shape_c(circle)
    {
    }

    void checkAnswer(Area user_area)
    {
        if (isAnswerCorrect(user_area))
        {
            status = QuestionStatus::Correct;
            wchar_t status_symbol = ')';
            std::wcout << L"Correct! :-" << status_symbol << std::endl;
            // std::thread add_points(incPoints);

            // // Wait for thread to finish.
            // add_points.join();
            user_pts++;
        }
        else
        {
            status = QuestionStatus::Incorrect;
            wchar_t status_symbol = '(';
            std::wcout << L"Incorrect... :-" << status_symbol << std::endl;
            std::cout << "\tExpected: " << expected_area << std::endl;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const ShapeAreaQuestion &question);
};

std::ostream &operator<<(std::ostream &os, const ShapeAreaQuestion &question)
{
    os << "Q" << question.question_number << ": Calculate the area of the following shape:" << std::endl;
    switch (question.shape_type)
    {
    case ShapeInQuestion::Rectangle:
        os << question.shape_r;
        break;
    case ShapeInQuestion::Triangle:
        os << question.shape_tr;
        break;
    case ShapeInQuestion::Circle:
        os << question.shape_c;
        break;
    default:
        os << "(no shape)";
        break;
    }
    os << std::endl;
    return os;
}

// Empty brace initialization means default value for the type (0UL for unsigned long)
Q_number_type ShapeAreaQuestion::question_count{};

Dist randomDist(int limit_val)
{
    Dist rand_res = rand() % limit_val + (Dist)((rand() % 100) / 100.);
    // std::cout << "Random distance value (limit: " << limit_val << "): " << rand_res << std::endl;
    return rand_res;
}

int main()
{
    srand(time(0));
    Rectangle q0_rectangle = Rectangle(randomDist(my_constants::MAX_DIST),
                                       randomDist(my_constants::MAX_DIST));

    RightAngledTriangle q1_triangle = RightAngledTriangle(randomDist(my_constants::MAX_DIST),
                                                          randomDist(my_constants::MAX_DIST));

    Circle q2_circle = Circle(randomDist(my_constants::MAX_DIST));

    // std::cout << "Printing rectangle info test: " << std::endl
    //           << q0_rectangle << std::endl;

    // std::cout << "Printing triangle info test: " << std::endl
    //           << q1_triangle << std::endl;

    // std::cout << "Printing circle info test: " << std::endl
    //           << q2_circle << std::endl;

    ShapeAreaQuestion shape_area_assessment[my_constants::MAX_POINTS] = {
        ShapeAreaQuestion(q0_rectangle),
        ShapeAreaQuestion(q1_triangle),
        ShapeAreaQuestion(q2_circle),
    };

    std::string results_header = R"CUSTOM_DELIMITER(
    =================
    | "( RESULTS )" |
    =================
    )CUSTOM_DELIMITER";

    // TODO: Fix the following issue: setting a status might not work (no reference to objects).
    for (int i = 0; i < my_constants::MAX_POINTS; i++)
    {
        Area user_ans;
        std::cout << shape_area_assessment[i];
        std::cout << "Your answer: ";
        std::cin >> user_ans;
        shape_area_assessment[i].checkAnswer(user_ans);
    }

    std::cout << results_header << std::endl;
    // const int final_user_points = getPoints();
    const int final_user_points{user_pts};
    register int possible_points{my_constants::MAX_POINTS};
    std::cout << "Score: " << final_user_points << "/" << possible_points << '\a' << std::endl;
    if (final_user_points >= my_constants::PASS_THRESHOLD)
        std::cout << "Test passed!" << std::endl;
    else
        std::cout << "Test failed." << std::endl;
    return 0;
}
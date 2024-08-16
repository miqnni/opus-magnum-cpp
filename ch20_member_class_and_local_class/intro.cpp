#include <iostream>
#include <string>

class Sample
{
private:
    static int st;

public:
    class SampleInnerPublic
    {
    public:
        SampleInnerPublic() {}
        SampleInnerPublic(int a, char b) : a(a), b(b) {}
        void printContent()
        {
            std::cout << "PUBLIC | a: " << a << "; b: " << b << "; [private static int in Sample: " << Sample::st << "]" << std::endl;
        }

    private:
        int a;
        char b;
    };

private:
    class SampleInnerPrivate
    {
    public:
        SampleInnerPrivate() {}
        SampleInnerPrivate(std::string info, double c) : info(info), c(c) {}
        void printContent()
        {
            std::cout << "PRIVATE | info: " << info << "; c: " << c << "; [private static int in Sample: " << Sample::st << "]" << std::endl;
        }

    private:
        std::string info;
        double c;
    };

public:
    Sample(int s0, int s1, int s2) : s0(s0), s1(s1), s2(s2)
    {
        innerPrivateObj = SampleInnerPrivate("My private object", s0 + static_cast<double>(s1) / s2);
        innerPublicObj = SampleInnerPublic(s0, 'A' + ((s1 + s2) % 26));
    }

    void masterPrint()
    {
        std::cout << "SAMPLE {" << s0 << ", " << s1 << ", " << s2 << "}" << "\n\t";
        innerPrivateObj.printContent();
        std::cout << "\t";
        innerPublicObj.printContent();
    }

private:
    int s0;
    int s1;
    int s2;
    SampleInnerPrivate innerPrivateObj;
    SampleInnerPublic innerPublicObj;
};

int Sample::st{10};

int main()
{
    Sample::SampleInnerPublic aa(13, 'g');
    aa.printContent();

    Sample sam(5, 3, 4);
    sam.masterPrint();

    return 0;
}
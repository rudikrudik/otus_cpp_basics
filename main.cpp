#include <iostream>
#include <limits>
#include <vector>
#include <numeric>

class IStatistics{
public:
    virtual ~IStatistics(){};

    virtual void update(double next) = 0;
    virtual const char * name() const = 0;
    virtual double result() const = 0;
};

class Min : public IStatistics {
public:
    Min() : number{std::numeric_limits<double>::max()}{
    } // Инициализируем number максимальным числом

    void update(double next) override{
        if(next < number){
            number = next;
        }
    }

    const char * name() const override{
        return "Minimum";
    }

    double result() const override{
        return number;
    }

private:
    double number;
}; // Минимальное число

class Max : public IStatistics{
public:
    Max() : number{std::numeric_limits<double>::min()}{
    } // Инициализируем number минимальным числом

    void update(double next) override{
        if(next > number){
            number = next;
        }
    }

    const char * name() const override{
        return "Maximum";
    }

    double result() const override{
        return number;
    }

private:
    double number;
}; // Максимальное число

class Mean : public IStatistics{
public:
    Mean() : number{0}, count{0}{}

    void update(double next) override{
        number += next;
        count++;
    }

    const char * name() const override{
        return "Arithmetic mean";
    }

    double result() const override{
        return number / count;
    }

private:
    double number;
    int count;
}; // Среднее арифметическое

class Std : public IStatistics{
public:
    void update(double next) override{
        massive.push_back(next);
    }

    const char * name() const override{
        return "Standard deviation";
    }

    double result() const override{
        double sumPowElem = 0;
        // Среднее арифметическое
        double sumElement = std::accumulate(massive.begin(), massive.end(), 0.0) / massive.size();
        // Считаем квадраты отклонений
        for (unsigned int i = 0; i < massive.size(); i++) {
            sumPowElem += pow(massive[i] - sumElement, 2);
        }
        // Среднеквадратичное отклонение
        return sqrt(sumPowElem / massive.size());
    }

private:
    std::vector<double> massive;
}; // Среднеквадратическое отклонение


int main() {
    const size_t size = 4;
    IStatistics *statistics[size];

    statistics[0] = new Min{};
    statistics[1] = new Max{};
    statistics[2] = new Mean{};
    statistics[3] = new Std{};

    double value = 0;

    while(std::cin >> value){
        for(int i = 0; i < size; i++){
            statistics[i]->update(value);
        }
    } // Заполняем экземпляры классов числами с консоли

    if (!std::cin.eof() && !std::cin.good()) {
        std::cerr << "Invalid input data\n";
        return 1;
    } // Выдаем ошибку если пользователь ввел не число

    for(int i = 0; i < size; i++){
        std::cout << statistics[i]->name() << ": " <<  statistics[i]->result() << std::endl;
    } // Выводим результат и имя

    for(int i = 0; i < size; i++){
        delete statistics[i];
    } // Вызываем деструкторы

    return 0;
}
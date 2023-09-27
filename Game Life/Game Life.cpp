#include <iostream>
#include <fstream>
#include <string>


const char Live = '*';
const char None = '-';

char** createarr(int rows, int cols) {
    char** arr = new char* [rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new char[cols];
    }
    return arr;
}

char death(int& counter2) {
    if (counter2 < 3 || counter2 > 4) return None;
    return Live;
}

char birth(int& counter) {
    if (counter == 3) return Live;
    return None;
}


int main() {
    int counter = 0;
    int counter2 = 0;
    int counter3 = 0;
    int t = 0;
    std::ifstream file("C:\\Users\\USER\\Desktop\\Game Life\\Gamestart.txt");
    std::string str;
    file >> str;
    const int rows = stoi(str);
    file >> str;
    const int cols = stoi(str);
    int Generation = 1;
    int alive = 0;

    // инициализаци€ масива arr
    char** arr = createarr(rows, cols);
    // инициализаци€ масива hold
    char** hold = createarr(rows, cols);

    // «аполнение масива arr
    for (int j = 0; j < rows; ++j) {
        for (int i = 0; i < cols; ++i) {
            arr[j][i] = None;
        }
    }

    while (!file.eof()) {
        file >> str;
        int y = stoi(str);
        file >> str;
        int x = stoi(str);
        arr[y][x] = Live;
        alive++;
    };

    // ћасив hold и вывод масива arr
    for (int j = 0; j < rows; ++j) {
        for (int i = 0; i < cols; ++i) {
            hold[j][i] = arr[j][i];
            std::cout << arr[j][i] << ' ';
        }
        std::cout << "\n";
    }
    std::cout << "Generation: " << Generation << '.';
    std::cout << " Alive cels: " << alive;
    if (alive == 0) { std::cout << "\nGame over. All cels dead"; return 0; }

      // –абота програмы
    while (t < 1) {
        for (int j = 0; j < rows; ++j) {
            for (int i = 0; i < cols; ++i) {
                counter = 0;
                counter2 = 0;

                // –абота по кра€м на удаление
                if (arr[0][i] == Live || arr[j][0] == Live || arr[j][cols - 1] == Live || arr[rows - 1][i] == Live) {

                    //дл€ левого верхнего угла
                    if (j == 0 && i == 0) {
                        for (int q = j; q <= j + 1; ++q) {
                            for (int w = i; w <= i + 1; ++w) {
                                if (arr[q][w] == Live) counter2++;
                            }
                        }
                        hold[j][i] = death(counter2);
                    }
                    //дл€ правого верхнего угла
                    else if (j == 0 && i == cols - 1) {
                        for (int q = j; q <= j + 1; ++q) {
                            for (int w = i - 1; w <= i; ++w) {
                                if (arr[q][w] == Live) counter2++;
                            }
                        }
                        hold[j][i] = death(counter2);
                    }
                    //дл€ левого нижнего угла
                    else if (j == rows - 1 && i == 0) {
                        for (int q = j - 1; q <= j; ++q) {
                            for (int w = i; w <= i + 1; ++w) {
                                if (arr[q][w] == Live) counter2++;
                            }
                        }
                        hold[j][i] = death(counter2);
                    }
                    //дл€ правого нижнего угла
                    else if (j == rows - 1 && i == cols - 1) {
                        for (int q = j - 1; q <= j; ++q) {
                            for (int w = i - 1; w <= i; ++w) {
                                if (arr[q][w] == Live) counter2++;
                            }
                        }
                        hold[j][i] = death(counter2);
                    }


                    // дл€ верхней границы
                    else if (j == 0 && i != 0 && j != rows - 1) {

                        for (int q = j; q <= j + 1; ++q) {
                            for (int w = i - 1; w <= i + 1; ++w) {
                                if (arr[q][w] == Live) counter2++;
                            }
                        }
                        hold[j][i] = death(counter2);

                    }

                    //ƒл€ левой границы
                    else if (i == 0 && j != 0 && i != cols - 1) {

                        for (int q = j - 1; q <= j + 1; ++q) {
                            for (int w = i; w <= i + 1; ++w) {
                                if (arr[q][w] == Live) counter2++;
                            }
                        }
                        hold[j][i] = death(counter2);

                    }

                    // дл€ правой границы
                    else if (i == cols - 1 && j != 0 && j != rows - 1) {

                        for (int q = j - 1; q <= j + 1; ++q) {
                            for (int w = i - 1; w <= i; ++w) {
                                if (arr[q][w] == Live) counter2++;
                            }
                        }
                        hold[j][i] = death(counter2);

                    }

                    // ƒл€ нижней границы
                    else if (j == rows - 1 && i != 0 && i != cols - 1) {

                        for (int q = j - 1; q <= j; ++q) {
                            for (int w = i - 1; w <= i + 1; ++w) {
                                if (arr[q][w] == Live) counter2++;
                            }
                        }
                        hold[j][i] = death(counter2);

                    }

                }

                // –абота по кра€м на добавление      
                if (arr[0][i] == None || arr[j][0] == None || arr[j][cols - 1] == None || arr[rows - 1][i] == None) {
                    //дл€ левого верхнего угла
                    if (j == 0 && i == 0) {
                        for (int q = j; q <= j + 1; ++q) {
                            for (int w = i; w <= i + 1; ++w) {
                                if (arr[q][w] == Live) counter++;
                            }
                        }
                        hold[j][i] = birth(counter);
                    }
                    //дл€ правого верхнего угла
                    else if (j == 0 && i == cols - 1) {
                        for (int q = j; q <= j + 1; ++q) {
                            for (int w = i - 1; w <= i; ++w) {
                                if (arr[q][w] == Live) counter++;
                            }
                        }
                        hold[j][i] = birth(counter);
                    }
                    //дл€ левого нижнего угла
                    else if (j == rows - 1 && i == 0) {
                        for (int q = j - 1; q <= j; ++q) {
                            for (int w = i; w <= i + 1; ++w) {
                                if (arr[q][w] == Live) counter++;
                            }
                        }
                        hold[j][i] = birth(counter);
                    }
                    //дл€ правого нижнего угла
                    else if (j == rows - 1 && i == cols - 1) {
                        for (int q = j - 1; q <= j; ++q) {
                            for (int w = i - 1; w <= i; ++w) {
                                if (arr[q][w] == Live) counter++;
                            }
                        }
                        hold[j][i] = birth(counter);
                    }
                    // дл€ верхней границы
                    else if (j == 0 && i != 0 && j != rows - 1) {

                        for (int q = j; q <= j + 1; ++q) {
                            for (int w = i - 1; w <= i + 1; ++w) {
                                if (arr[q][w] == Live) counter++;
                            }
                        }
                        hold[j][i] = birth(counter);
                    }
                    //ƒл€ левой границы
                    else if (i == 0 && j != 0 && i != cols - 1) {

                        for (int q = j - 1; q <= j + 1; ++q) {
                            for (int w = i; w <= i + 1; ++w) {
                                if (arr[q][w] == Live) counter++;
                            }
                        }
                        hold[j][i] = birth(counter);
                    }
                    // дл€ правой границы
                    else if (i == cols - 1 && j != 0 && j != rows - 1) {

                        for (int q = j - 1; q <= j + 1; ++q) {
                            for (int w = i - 1; w <= i; ++w) {
                                if (arr[q][w] == Live) counter++;
                            }
                        }
                        hold[j][i] = birth(counter);
                    }
                    // ƒл€ нижней границы
                    else if (j == rows - 1 && i != 0 && i != cols - 1) {

                        for (int q = j - 1; q <= j; ++q) {
                            for (int w = i - 1; w <= i + 1; ++w) {
                                if (arr[q][w] == Live) counter++;
                            }
                        }
                        hold[j][i] = birth(counter);
                    }




                }

            }
        }

        // –абота в середине
        for (int j = 1; j < rows - 1; ++j) {
            for (int i = 1; i < cols - 1; ++i) {
                counter = 0;
                counter2 = 0;
                // ƒл€ середины на удаление *
                if (arr[j][i] == Live) {
                    for (int q = j - 1; q <= j + 1; ++q) {
                        for (int w = i - 1; w <= i + 1; ++w) {
                            if (arr[q][w] == Live) counter2++;
                        }
                    }
                    hold[j][i] = death(counter2);
                }
                // ƒл€ середины на рождение *
                if (arr[j][i] == None) {
                    for (int q = j - 1; q <= j + 1; ++q) {
                        for (int w = i - 1; w <= i + 1; ++w) {
                            if (arr[q][w] == Live)counter++;
                        }
                    }
                    hold[j][i] = birth(counter);
                }
            }
        }

        std::cout << "\n" << "\n" << "\n";
        alive = 0;
        counter3 = 0;
        for (int j = 0; j < rows; ++j) {
            for (int i = 0; i < cols; ++i) {
                if (hold[j][i] == arr[j][i])counter3++;
                if (hold[j][i] == Live) alive++;
                arr[j][i] = hold[j][i];
                std::cout << arr[j][i] << ' ';
            }
            std::cout << "\n";
        }
        if (counter3 == cols * rows) t = 1;

        std::cout << "Generation:  " << ++Generation << '.';
        std::cout << " Alive cels: " << alive;
        if (alive == 0) t = 2;

    }

    if (t == 1)std::cout << "\nThe world stagnated. Game over";
    if (alive == 0)std::cout << "\nGame over. All cels dead";

    return 0;
}
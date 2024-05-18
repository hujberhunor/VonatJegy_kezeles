#include "gtest_lite.h"
#include "mav.h"
#include "vonat.h"
#include "allomas.h"
#include "ido.h"
#include "seged.h"
#include <sstream>
#include <fstream>

void testMavAdd() {
    Mav mav;
    Vonat vonat1(1, "Budapest", "Szeged", 10, Ido(8, 0), Ido(10, 0));
    Vonat vonat2(2, "Szeged", "Debrecen", 8, Ido(12, 0), Ido(14, 0));

    mav.add(vonat1);
    mav.add(vonat2);

    TEST(Mav, AddFunction) {
        EXPECT_EQ(mav.getSize(), 2);
        EXPECT_EQ(mav.getVonatAt(1).getSzam(), 1);
        EXPECT_EQ(mav.getVonatAt(2).getSzam(), 2);
    } END
}

void testMavKiir() {
    Mav mav;
    Vonat vonat1(1, "Budapest", "Szeged", 10, Ido(8, 0), Ido(10, 0));
    Vonat vonat2(2, "Szeged", "Debrecen", 8, Ido(12, 0), Ido(14, 0));

    mav.add(vonat1);
    mav.add(vonat2);

    TEST(Mav, KiirFunction) {
        std::stringstream output;
        std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());
        mav.kiir();
        std::cout.rdbuf(oldCoutBuffer);

        std::string expectedOutput = "--- 1.vonat ---\n"
                                     "1: Budapest -> Szeged, 10 kocsival, Indulás: 08:00, Érkezés: 10:00\n\n"
                                     "--- 2.vonat ---\n"
                                     "2: Szeged -> Debrecen, 8 kocsival, Indulás: 12:00, Érkezés: 14:00\n\n";
        EXPECT_EQ(output.str(), expectedOutput);
    } END
}

void testMavKiirAt() {
    Mav mav;
    Vonat vonat1(1, "Budapest", "Szeged", 10, Ido(8, 0), Ido(10, 0));
    Vonat vonat2(2, "Szeged", "Debrecen", 8, Ido(12, 0), Ido(14, 0));

    mav.add(vonat1);
    mav.add(vonat2);

    TEST(Mav, KiirAtFunction) {
        std::stringstream output;
        std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());
        mav.kiirAt(0);
        std::cout.rdbuf(oldCoutBuffer);

        std::string expectedOutput = "1.vonat\n"
                                     "1: Budapest -> Szeged, 10 kocsival, Indulás: 08:00, Érkezés: 10:00\n";
        EXPECT_EQ(output.str(), expectedOutput);
    } END
}

void testMavBeolvas() {
    // Create a temporary test file
    const char* testFilename = "./test_vonatok.txt";
    std::ofstream outFile(testFilename);
    outFile << "1 Budapest Szeged 10 08:00 10:00\n"
            << "2 Szeged Debrecen 8 12:00 14:00\n";
    outFile.close();

    // Change the file to be read by the Mav class to the test file
    Mav mav;
    std::rename(testFilename, "./vonatok.txt");

    TEST(Mav, BeolvasFunction) {
        mav.beolvas();
        EXPECT_EQ(mav.getSize(), 2);
        EXPECT_EQ(mav.getVonatAt(1).getSzam(), 1);
        EXPECT_EQ(mav.getVonatAt(2).getSzam(), 2);
    } END

    // Clean up the test file
    std::remove("./vonatok.txt");
}

void testMavAddTrain() {
    // Create a temporary test file
    const char* testFilename = "./test_vonatok.txt";
    std::ofstream outFile(testFilename);
    outFile << "1 Budapest Szeged 10 08:00 10:00\n";
    outFile.close();

    // Change the file to be read by the Mav class to the test file
    std::rename(testFilename, "./vonatok.txt");

    Mav mav;
    std::streampos currPos = 0;

    TEST(Mav, AddTrainFunction) {
        Allomas indulo("Szeged"), veg("Debrecen");
        Ido indulas(12, 0), erkezes(14, 0);
        mav.addTrain(currPos, 2, indulo, veg, 8, indulas, erkezes);

        std::ifstream inFile("./vonatok.txt");
        std::stringstream buffer;
        buffer << inFile.rdbuf();
        inFile.close();

        std::string expectedContent = "1 Budapest Szeged 10 08:00 10:00\n"
                                      "2 Szeged Debrecen 8 12:00 14:00\n";
        EXPECT_EQ(buffer.str(), expectedContent);
    } END

    // Clean up the test file
    std::remove("./vonatok.txt");
}

int main() {
    testMavAdd();
    testMavKiir();
    testMavKiirAt();
    testMavBeolvas();
    testMavAddTrain();

    GTEND(std::cerr);  // Csak C(J)PORTA működéséhez kell
    return 0;
}


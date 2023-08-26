#include <iostream>
#include <fstream>
#include "input.h"
#include "Element.h"
using namespace std;

int main()
{

    Element* array = nullptr;
    do
    {
        system("cls");
        cout << "\n\t[ H  ]                                                                                                [ He ]";
        cout << "\n\t[ Li ][ Be ]                                                            [  B ][  C ][  N ][  O ][  F ][ Ne ]";
        cout << "\n\t[ Na ][ Mg ]                                                            [ Al ][ Si ][  P ][  S ][ Cl ][ Ar ]";
        cout << "\n\t[  K ][ Ca ][ Sc ][ Ti ][  V ][ Cr ][ Mn ][ Fe ][ Co ][ Ni ][ Cu ][ Zn ][ Ga ][ Ge ][ As ][ Se ][ Br ][ Kr ]";
        cout << "\n\t[ Rb ][ Sr ][  Y ][ Zr ][ Nb ][ Mo ][ Tc ][ Ru ][ Rh ][ Pd ][ Ag ][ Cd ][ In ][ Sn ][ Sb ][ Te ][  I ][ Xe ]";
        cout << "\n\t[ Cs ][ Ba ]  *   [ Hf ][ Ta ][  W ][ Re ][ Os ][ Ir ][ Pt ][ Au ][ Hg ][ Tl ][ Pb ][ Bi ][ Po ][ At ][ Rn ]";
        cout << "\n\t[ Fr ][ Ra ]  **  [ Rf ][ Db ][ Sg ][ Bh ][ Hs ][ Mt ][ Ds ][ Rg ][ Cn ][ Nh ][ Fl ][ Mc ][ Lv ][ Ts ][ Og ]";
        cout << '\n';
        cout << "\n\t              *   [ La ][ Ce ][ Pr ][ Nd ][ Pm ][ Sm ][ Eu ][ Gd ][ Tb ][ Dy ][ Ho ][ Er ][ Tm ][ Yb ][ Lu ]";
        cout << "\n\t              **  [ Ac ][ Th ][ Pa ][  U ][ Np ][ Pu ][ Am ][ Cm ][ Bk ][ Cf ][ Es ][ Fm ][ Md ][ No ][ Lr ]";
        cout << "\n\t";
        cout << "\n\tIn chemistry, the periodic table is a tabular display of the chemical elements. It is widely used in";
        cout << "\n\tchemistry, physics, and other sciences, and is generally seen as an icon of chemistry. It is a graphic";
        cout << "\n\tformulation of the periodic law, which states that the properties of the chemical elements exhibit a";
        cout << "\n\tperiodic dependence on their atomic numbers.";
        cout << '\n';
        cout << "\n\tCMPR121 EXAM 1 - Periodic Table of Elements (using struct ADT) by Francisco Ramos";

        cout << "\n\t" << string(80, char(205));
        cout << "\n\t1. Dynamic Array of structure elements";//submenu
        cout << "\n\t2. Structure Elements from Binary File";//submenu
        cout << "\n\t3. Structure Element size info (5pts Extra)";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t0. Exit";
        cout << "\n\t" << string(80, char(205));

        int choice = inputInteger("\n\tChoose one of the following options :", 0, 3);

        switch (choice)
        {
        case 0: 
            EXIT_SUCCESS;
            break;
        case 1:
        {
            do
            {

                system("cls");
                cout << "\n\tDynamic Array of structure elements";
                cout << "\n\t" << string(60, char(205));
                cout << "\n\t1. Read binary structure input data file and store elements into an dynamic array";
                cout << "\n\t2. Display 118 elements from the dynamic array";
                cout << "\n\t3. Sort ascending order the dynamic array by atomic number(5 points Extra)";
                cout << "\n\t4. Sort descending order the dynamic array by atomic number(5 points Extra)";
                cout << "\n\t5. Binary search for an element's atomic number from the array (10 points Extra)";
                cout << "\n\t6. Sequencial search for an element's symbol from the array";
                cout << "\n\t7. Update an element by atomic number from the array(10 points Xtra)";
                cout << "\n\t8. Save the dynamic array into a binary data file";
                cout << "\n\t" << string(60, char(196));
                cout << "\n\t0. Return";
                cout << "\n\t" << string(60, char(205));


                int choice = inputInteger("\n\tChoose one of the following options :", 0, 8);

                switch (choice)
                {
                case 0:
                {
                    delete[] array;
                    return 0;
                }
               
                case 1:
                {
                    array = new Element[140];

                    string filename = inputString("\n\tEnter a binary data file: ", false);

                    fstream inputfile;
                    inputfile.open(filename, ios::in | ios::binary);

                    int index = 0;

                    if (inputfile.fail()) //validation
                    {
                        cout << "\n\tERROR: file, " << filename << ", does not exist. Try again\n";
                        system("\n\tpause");
                        break;
                    }
                    while (!inputfile.eof())//reading
                    {
                        Element e;
                        (inputfile.read(reinterpret_cast<char*> (&e), sizeof(e)));
                        array[index++] = e;
                    }

                    inputfile.close();
                    cout << "\n\tCompleted read structure data and stored into an dynamic array.\n";
                    system("\n\tpause");
                }
                break;
                case 2: //display
                {
                    for (int i = 0; i < 117; i++)
                    {
                        displayElement(array[i]);
                        cout << '\n';
                    }
                    system("\n\tpause");
                }
                break;

                case 6: // sequential search 
                {
                    system("cls");
                    cout << "\n\t[ H  ]                                                                                                [ He ]";
                    cout << "\n\t[ Li ][ Be ]                                                            [  B ][  C ][  N ][  O ][  F ][ Ne ]";
                    cout << "\n\t[ Na ][ Mg ]                                                            [ Al ][ Si ][  P ][  S ][ Cl ][ Ar ]";
                    cout << "\n\t[  K ][ Ca ][ Sc ][ Ti ][  V ][ Cr ][ Mn ][ Fe ][ Co ][ Ni ][ Cu ][ Zn ][ Ga ][ Ge ][ As ][ Se ][ Br ][ Kr ]";
                    cout << "\n\t[ Rb ][ Sr ][  Y ][ Zr ][ Nb ][ Mo ][ Tc ][ Ru ][ Rh ][ Pd ][ Ag ][ Cd ][ In ][ Sn ][ Sb ][ Te ][  I ][ Xe ]";
                    cout << "\n\t[ Cs ][ Ba ]  *   [ Hf ][ Ta ][  W ][ Re ][ Os ][ Ir ][ Pt ][ Au ][ Hg ][ Tl ][ Pb ][ Bi ][ Po ][ At ][ Rn ]";
                    cout << "\n\t[ Fr ][ Ra ]  **  [ Rf ][ Db ][ Sg ][ Bh ][ Hs ][ Mt ][ Ds ][ Rg ][ Cn ][ Nh ][ Fl ][ Mc ][ Lv ][ Ts ][ Og ]";
                    cout << '\n';
                    cout << "\n\t              *   [ La ][ Ce ][ Pr ][ Nd ][ Pm ][ Sm ][ Eu ][ Gd ][ Tb ][ Dy ][ Ho ][ Er ][ Tm ][ Yb ][ Lu ]";
                    cout << "\n\t              **  [ Ac ][ Th ][ Pa ][  U ][ Np ][ Pu ][ Am ][ Cm ][ Bk ][ Cf ][ Es ][ Fm ][ Md ][ No ][ Lr ]";
                    cout << "\n\t";

                    bool bfound = false;
                    string atomicSymbol = inputString("\n\tEnter an atomic symbol: ", false);
                    for (int i = 0; i < 118; i++)
                    {
                        if (_stricmp(atomicSymbol.c_str(), array[i].symbol) == 0)
                        {
                            displayElement(array[i]);
                            bfound = true;
                            break;
                        }
                    }

                    if (!bfound)
                        cout << "\n\tERROR: The element with symbol(" << atomicSymbol << ") not found.\n";
                    system("\n\tpause");
                }
                break;
                case 8:
                {
                    if (array == nullptr)
                    {
                        cout << "\n\tERROR: no data in array to write. Try again.\n";
                        system("\n\tpause");
                        break;
                    }
                    string filename = inputString("\n\tEnter a binary data file to save: ", false);

                    fstream outputfile;
                    outputfile.open(filename, ios::out | ios::binary);

                    if (outputfile.fail())
                    {
                        cout << "\n\tERROR: file, " << filename << ", cannot be created. Try again.\n";
                        system("\n\tpause");
                        break;
                    }

                    for (int i = 0; i < 118; i++)
                    {
                        outputfile.write(reinterpret_cast<char*>(&array[i]), sizeof(Element));
                    }

                    outputfile.close();
                    cout << "\n\tCompleted saving dynamic array into binary data file.\n";
                    system("\n\tpause");
                }
                break;
                }
            } while (true);
        }break;
        case 2:
        {


            system("cls");
            cout << "\n\tDynamic Array of structure elements";
            cout << "\n\t" << string(60, char(205));
            cout << "\n\t1. Specify the binary structure input/output data file";
            cout << "\n\t2. Display ALL elements from the file";
            cout << "\n\t3. Sequencial search for an element's atomic number from the file";
            cout << "\n\t4. Sequencial search for an element's symbol from the file";
            cout << "\n\t5. Directly update an element by its atomic number into the file (10 points Xtra)";
            cout << "\n\t" << string(60, char(196));
            cout << "\n\t0. Return";
            cout << "\n\t" << string(60, char(205));

            int choice = inputInteger("\n\tChoose one of the following options :", 0, 5);

            switch (choice)
            {
            case 0: break;
            case 1:
            {
                array = new Element[140];

                string filename = inputString("\n\tEnter a binary data file: ", false);

                fstream inputfile;
                inputfile.open(filename, ios::in | ios::binary);

                int index = 0;

                if (inputfile.fail()) //validation
                {
                    cout << "\n\tERROR: file, " << filename << ", does not exist. Try again\n";
                    system("\n\tpause");
                    break;
                }
                while (!inputfile.eof())//reading
                {
                    Element e;
                    (inputfile.read(reinterpret_cast<char*> (&e), sizeof(e)));
                    array[index++] = e;
                }

                inputfile.close();
                cout << "\n\tCompleted read structure data and stored into an dynamic array.\n";
                system("\n\tpause");
            }break;
            case 2:
            {
                for (int i = 0; i < 117; i++)
                {
                    displayElement(array[i]);
                    cout << '\n';
                }
                system("\n\tpause");
            }break;
            case 3:
            {
                system("cls");
                cout << "\n\t[   1 ]                                                                                                                [   2 ]";
                cout << "\n\t[   3 ][   4 ]                                                                      [   5 ][   6 ][   7 ][   8 ][   9 ][  10 ]";
                cout << "\n\t[  11 ][  12 ]                                                                      [  13 ][  14 ][  15 ][  16 ][  17 ][  18 ]";
                cout << "\n\t[  19 ][  20 ][  21 ][  22 ][  23 ][  24 ][  25 ][  26 ][  27 ][  28 ][  29 ][  30 ][  31 ][  32 ][  33 ][  34 ][  35 ][  36 ]";
                cout << "\n\t[  37 ][  38 ][  39 ][  40 ][  41 ][  42 ][  43 ][  44 ][  45 ][  46 ][  47 ][  48 ][  49 ][  50 ][  51 ][  52 ][  53 ][  54 ]";
                cout << "\n\t[  55 ][  56 ]   *   [  72 ][  73 ][  74 ][  75 ][  76 ][  77 ][  78 ][  79 ][  80 ][  81 ][  82 ][  83 ][  84 ][  85 ][  86 ]";
                cout << "\n\t[  87 ][  88 ]   **  [ 104 ][ 105 ][ 106 ][ 107 ][ 108 ][ 109 ][ 110 ][ 111 ][ 112 ][ 113 ][ 114 ][ 115 ][ 116 ][ 117 ][ 118 ]";
                cout << '\n';
                cout << "\n\t                 *   [  57 ][  58 ][  59 ][  60 ][  61 ][  62 ][  63 ][  64 ][  65 ][  66 ][  67 ][  68 ][  69 ][  70 ][  71 ]";
                cout << "\n\t                 **  [  89 ][  90 ][  91 ][  92 ][  93 ][  94 ][  95 ][  96 ][  97 ][  98 ][  99 ][ 100 ][ 101 ][ 102 ][ 103 ]";
                cout << "\n\t";

                bool bfound = false;
                int atomicNumber = inputInteger("\n\tEnter an element's atomic number to search (1...118 or 0 - STOP): ");
                for (int i = 0; i < 118; i++)
                {
                    if (atomicNumber == array[i].atomicNumber)
                    {
                        displayElement(array[i]);
                        bfound = true;
                        break;
                    }
                }

                if (!bfound)
                    cout << "\n\tERROR: The element with atomic number(" << atomicNumber << ") not found.\n";
                system("\n\tpause");
            }break;
            case 4:
            {
                system("cls");
                cout << "\n\t[ H  ]                                                                                                [ He ]";
                cout << "\n\t[ Li ][ Be ]                                                            [  B ][  C ][  N ][  O ][  F ][ Ne ]";
                cout << "\n\t[ Na ][ Mg ]                                                            [ Al ][ Si ][  P ][  S ][ Cl ][ Ar ]";
                cout << "\n\t[  K ][ Ca ][ Sc ][ Ti ][  V ][ Cr ][ Mn ][ Fe ][ Co ][ Ni ][ Cu ][ Zn ][ Ga ][ Ge ][ As ][ Se ][ Br ][ Kr ]";
                cout << "\n\t[ Rb ][ Sr ][  Y ][ Zr ][ Nb ][ Mo ][ Tc ][ Ru ][ Rh ][ Pd ][ Ag ][ Cd ][ In ][ Sn ][ Sb ][ Te ][  I ][ Xe ]";
                cout << "\n\t[ Cs ][ Ba ]  *   [ Hf ][ Ta ][  W ][ Re ][ Os ][ Ir ][ Pt ][ Au ][ Hg ][ Tl ][ Pb ][ Bi ][ Po ][ At ][ Rn ]";
                cout << "\n\t[ Fr ][ Ra ]  **  [ Rf ][ Db ][ Sg ][ Bh ][ Hs ][ Mt ][ Ds ][ Rg ][ Cn ][ Nh ][ Fl ][ Mc ][ Lv ][ Ts ][ Og ]";
                cout << '\n';
                cout << "\n\t              *   [ La ][ Ce ][ Pr ][ Nd ][ Pm ][ Sm ][ Eu ][ Gd ][ Tb ][ Dy ][ Ho ][ Er ][ Tm ][ Yb ][ Lu ]";
                cout << "\n\t              **  [ Ac ][ Th ][ Pa ][  U ][ Np ][ Pu ][ Am ][ Cm ][ Bk ][ Cf ][ Es ][ Fm ][ Md ][ No ][ Lr ]";
                cout << "\n\t";

                bool bfound = false;
                string atomicSymbol = inputString("\n\tEnter an atomic symbol: ", false);
                for (int i = 0; i < 118; i++)
                {
                    if (_stricmp(atomicSymbol.c_str(), array[i].symbol) == 0)
                    {
                        displayElement(array[i]);
                        bfound = true;
                        break;
                    }
                }

                if (!bfound)
                    cout << "\n\tERROR: The element with symbol(" << atomicSymbol << ") not found.\n";
                system("\n\tpause");
            }break;
            }
        }
        case 3:
        {

        }break;

        }

        return 0;
    } while (true);
}

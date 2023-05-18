#include <iostream>
#include <vector>

using namespace std;

const int INVENTORY_LIMIT = 20;
const int FREE_SPACE_LIMIT = 10;
const int EXTRA_SPACE_PRICE = 100;

vector<string> inventory;
vector<string> weaponOptions = {
       "Espada", "Hacha", "Arco", "Daga", "Maza", "Bastón", "Lanza", "Ballesta", "Martillo", "Varita",
        "Cuchillos arrojadizos", "Estoque", "Bolsa", "Katana", "Gran espada", "Arco largo", "Hacha de batalla",
        "Martillo de guerra", "Crucifijo", "Espada corta", "Guadaña", "Bumerán", "Claymore", "Nunchaku",
        "Guante de box", "Bomba", "Latigo de cadena", "Bate", "Shuriken", "Blowgun", "Slingshot",
        "Tridente", "Polearm", "Dagas del maestro del viento", "Chakram", "Sai", "Double-bladed sword",
        "Crossblade", "Picos", "Ventilador", "Estrellas ninja", "Hand cannon", "latigo",
        "Manopla", "Honda", "Rueda", "Bolas", "Piedra", "Palo de policia", "Katana", "Espada rota"
    };
int gems = 1500;

void showInventory() {
    cout << "inventario: \n";
    for (const string& item : inventory) {
        cout << item << ", ";
    }
    cout << endl;
}

void showWeaponOptions(const vector<string>& weaponOptions) {
    cout << "Elige un arma: " << endl;
    for (int i = 0; i < weaponOptions.size(); ++i) {
        cout << i + 1 << ". " << weaponOptions[i] << endl;
    }
    cout << "Tu decicion: ";
}

void removeWeaponOption(vector<string>& weaponOptions, int index) {
    weaponOptions.erase(weaponOptions.begin() + index);
}

bool isNumber(const string& input) {
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(nullptr));
    int choice;

    do {
        cout << "Elige un arma:" << endl;
        cout << "1. Añade un arma" << endl;
        cout << "2. Termina el juego" << endl;
        cout << "Tus opciones: ";
        string input;
        cin >> input;

        if (!isNumber(input)) {
            cout << "Porfavor escirbe un numero" << endl;
            continue;
        }

        choice = stoi(input);

         switch (choice) {
            case 1: {
                if (inventory.size() < INVENTORY_LIMIT) {
                    vector<string> optionsToShow;
                    int numOptions = min(3, static_cast<int>(weaponOptions.size()));
                    for (int i = 0; i < numOptions; ++i) {
                        int randomIndex = rand() % weaponOptions.size();
                        optionsToShow.push_back(weaponOptions[randomIndex]);
                        removeWeaponOption(weaponOptions, randomIndex);
                    }

                    showWeaponOptions(optionsToShow);
                    int weaponChoice;
                    cin >> weaponChoice;

                    if (weaponChoice >= 1 && weaponChoice <= optionsToShow.size()) {
                        string newWeapon = optionsToShow[weaponChoice - 1];
                        if (inventory.size() >= INVENTORY_LIMIT - FREE_SPACE_LIMIT) {
                            cout << "Ya no hay espacio gratis en tu inventario" << endl;
                            cout << "Elige una opcion:" << endl;
                            cout << "1. Cambiala por otra arma" << endl;
                            cout << "2. Continuar sin el arma" << endl;
                            cout << "3. Comprar un espacio por " << EXTRA_SPACE_PRICE << " gemas" << endl;
                            cout << "Your choice: ";
                            int replaceChoice;
                            cin >> replaceChoice;
                            switch (replaceChoice) {
                                case 1: {
                                    cout << "Elige el arma a remplazar: " << endl;
                                    showInventory();
                                    int replaceIndex;
                                    cin >> replaceIndex;
                                    if (replaceIndex >= 1 && replaceIndex <= inventory.size()) {
                                        inventory[replaceIndex - 1] = newWeapon;
                                        cout << "Arma cambiada" << endl;
                                        showInventory();
                                    } else {
                                        cout << "Arma invalida" << endl;
                                    }
                                    break;
                                }
                                case 2:
                                    cout << "Arma no elegida" << endl;
                                    break;
                                case 3:
                                    if (gems >= EXTRA_SPACE_PRICE) {
                                        gems -= EXTRA_SPACE_PRICE;
                                        inventory.push_back(newWeapon);
                                        cout << "Arma añadida a tu inventario." << endl;
                                        cout << "Espacio extra comprado, Espacio en tu inventario es : " << inventory.size() << endl;
                                         cout << "Tus gemas = " <<gems<< endl;
                                    } else {
                                        cout << "No hay gemas" << endl;
                                    }
                                    break;
                                default:
                                    cout << "Opcion invalida" << endl;
                                    break;
                            }
                        } else {
                            inventory.push_back(newWeapon);
                            cout << "Arma añadida a tu inventario" << endl;
                        }
                    } else {
                        cout << "Opcion invalida de arma" << endl;
                    }
                } else {
                    cout << "Inventario esta lleno" << endl;
                }

                showInventory();
                break;
            }
            case 2:
                cout << "Saliendo del programa FIN DEL JUEGO" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    } while (choice != 2);

    return 0;
}
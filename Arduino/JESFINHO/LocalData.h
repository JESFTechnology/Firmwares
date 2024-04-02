#include <EEPROM.h>

// Define the address of the EEPROM location where the data will be stored
const int EEPROM_SIZE = 512; // Tamanho da EEPROM
const int SSID_SIZE = 32;   // Tamanho máximo do SSID
const int PASS_SIZE = 64;   // Tamanho máximo da senha
const int ID_SIZE = 96;   // Tamanho máximo do SSID

// Endereços na EEPROM
const int SSID_ADDRESS = 0;
const int PASS_ADDRESS = SSID_SIZE;
const int ID_ADDRESS = PASS_SIZE;

void beginEEPROM(){
  EEPROM.begin(EEPROM_SIZE);
}

// Write data to the specified EEPROM address

void salvarDadoEEPROM(int address, int size, String data) {
  char charData[size];
  data.toCharArray(charData, size);
  for (int i = 0; i < size; i++) {
    EEPROM.write(address + i, charData[i]);
  }
  EEPROM.commit();
}

void limparEEPROM(){
  int size = EEPROM.length();
  for (int i = 0; i < size; i++) {
    EEPROM.write(i, 0);
  }
  EEPROM.commit();
}

String puxarDadoEEPROM(int address, int size) {
  String data = "";
  for (int i = 0; i < size; i++) {
    char c = EEPROM.read(address + i);
    if (c == 0) {
      break;
    }
    data += c;
  }
  return data;
}

String meuID(){
  String a = puxarDadoEEPROM(ID_ADDRESS, ID_SIZE);
  return a;
}

String minhaSenha(){
  String a = puxarDadoEEPROM(PASS_ADDRESS, PASS_SIZE);
  return a;
}

String meuSSID(){
  String a = puxarDadoEEPROM(SSID_ADDRESS, SSID_SIZE);
  return a;
}

void salvarWIFI(String ssid, String senha){
  salvarDadoEEPROM(SSID_ADDRESS, SSID_SIZE, ssid);
  salvarDadoEEPROM(PASS_ADDRESS, PASS_SIZE, senha);
}

void salvarID(String ID){
  salvarDadoEEPROM(ID_ADDRESS, ID_SIZE, ID);
}

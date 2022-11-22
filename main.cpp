#include <iostream>
#include <cstdio>

using namespace std;

// very slow iterative hash function
unsigned int slowHash(int seed){
  for (int i = 0; i < 150000000; ++i){
    seed = seed * 1103515245 + 12345;
  }
  return seed;
}

// returns the nth character of the secret PIN (n=index)
// slow-hashes the nth secret to yield the nth pin char
char getPinCharacter(int secret[], int index) {
  return '1' + (slowHash(secret[index]) % 4);
}

int main(int argc, char *argv[])
{
  srand(0xDEADBEEF + 2 * 0x1337);
  int secret[4] = {
    rand(), rand(), rand(), rand()
  };

  // if command line argument isn't passed
  // prompt user to re-execute program with pin passed via cmdline
  if (argc < 2) {
    cout << "Please supply a 4 digit PIN via commandline argument." << endl;
    exit(0);
  }

  // otherwise check if the PIN code is valid
  char* pin = argv[1];

  // PIN is length 4
  // loop checking each PIN character, pin[0..3]
  for (int i = 0; i <= 3; ++i) {
    if (pin[i] != getPinCharacter(secret, i)) {
      cout << "Invalid PIN. You lose." << endl;
      exit(0);
    }
  }

  // if we got to this point, they won!
  cout << "\033[1;31m\nNice job. You won!\033[0m\n" << endl;
}
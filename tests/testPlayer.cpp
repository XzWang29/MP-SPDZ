#include <iostream>
#include "../Networking/Player.h"
using namespace std;

int main()
{
	cout << "starting  !!" << endl;
	int player = 0;
	int nplayers = 2;
	const char* servername = "127.0.0.1";
	int pnb = 8000;
	int port = 8001;
	const Names n1 = Names(0, 8001, Names::DEFAULT_PORT, "127.0.0.1");
	cout << "Success !!" << endl;
	return 0;
}
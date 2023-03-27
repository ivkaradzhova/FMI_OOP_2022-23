#include <iostream>
#include <fstream>

const int MAX_SIZE = 64;

struct User {
	char username[MAX_SIZE];
	char password[MAX_SIZE];
};

struct Event {
	char description[MAX_SIZE];
	char date[11];
	char hour[6];
};


int main() {
	std::ofstream oFileName;
	oFileName.open("users.txt", std::ios::out | std::ios::binary);
	User user1 = { "member", "test123456" };
	oFileName.write((char*)&user1, sizeof(user1));

	oFileName.close();

	std::ifstream iFileName;
	iFileName.open("users.txt", std::ios::in);

	if (!iFileName) {
		std::cerr << "File couldn’t be opened!\n";
		return 1;
	}

	while (true) {
		User user;
		iFileName.read((char*)&user, sizeof(user));
		if (iFileName.eof()) break;
		if (strcmp(user.username, "member") == 0 && strcmp(user.password, "test123456") == 0) {
			std::cout << "Success" << std::endl;
		}
	}

	iFileName.close();
	return 0;
}
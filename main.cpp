#include <iostream>
#include <string>

using namespace std;

template <typename T>
class String_manipulator {
private:
	T data;
public:
	String_manipulator(T data) : data(data) {}

	void to_upper_case() {
		for (int i = 0; i < data.size(); i++) {
			if (data[i] >= 'a' && data[i] <= 'z') {
				data[i] -= 32;
			}
		}
	}

	void to_lower_case() {
		for (int i = 0; i < data.size(); i++) {
			if (data[i] >= 'A' && data[i] <= 'Z') {
				data[i] += 32;
			}
		}
	}

	void reverse() {
		for (int i = 0; i < data.size() / 2; i++) {
			swap(data[i], data[data.size() - i - 1]);
		}
	}

	void concatenate(T str) {
		data += str;
	}

	friend ostream& operator<<(ostream& out, const String_manipulator& sm) {
		out << sm.data;
		return out;
	}

	~String_manipulator() {}

};

int main() {
	String_manipulator<string> sm("Hello World");
	sm.to_upper_case();
	cout << sm << endl;
	sm.to_lower_case();
	cout << sm << endl;
	sm.reverse();
	cout << sm << endl;
	sm.concatenate("!");
	cout << sm << endl;


	return 0;
}

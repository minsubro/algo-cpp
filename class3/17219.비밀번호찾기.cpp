#include <iostream>
#include <map>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::map<std::string, std::string> map;
	int n, m; std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::string domain, password;
		std::cin >> domain >> password;
		map.insert(std::make_pair(domain, password));
	}
	for (int i = 0; i < m; i++) {
		std::string str;
		std::cin >> str;
		std::cout << map[str] << "\n";
	}
}
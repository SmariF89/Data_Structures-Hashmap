all:
	g++ -Wall -pedantic -ggdb Contact.cpp ContactList.cpp ContactManager.cpp ContactNode.cpp InteractivePhoneBook.cpp main.cpp StringContactMap.cpp Hash.cpp StringContactPair.cpp

map:
	g++ -Wall -pedantic -ggdb Contact.cpp ContactList.cpp ContactNode.cpp main.cpp StringContactMap.cpp Hash.cpp StringContactPair.cpp

list:
	g++ -Wall -pedantic -ggdb Contact.cpp ContactList.cpp ContactNode.cpp main.cpp Hash.cpp StringContactPair.cpp

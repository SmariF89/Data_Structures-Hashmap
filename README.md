# Data_Structures-Hashmap
This is a contact book which is implemented using a chained hashmap to keep track of the contacts. 

The hashmap allows for a quick retrieval of data using keys and their hashed values as indices. The implementation of the hashmap is located in the StringContactMap class, it uses the ContactList class (a singly linked list) to chain values that happen to get the same index in the map. ContactList uses the ContactNode struct for its nodes and the ContactNode struct uses the StringContactPair struct as its value (data). Finally, the StringContactPair contains the  key and value of map's content.

It looks like this: StringContactMap->ContactList->ContactNode->StringContactPair.

The hashmap implements basic methods such as size, add, get, contains and remove. It also has a function which allows for a prefix search and it overloads the << operator. Furthermore, the hashmap has two crucial private functions: load_check and rebuild. load_check checks if the hashmap has exceeded its constant maximum load (with too much chaining) and calls rebuild if it has. Rebuild tears down the entire data structure and rebuilds it with double the capacity before finally readding all of the data.

The ContactManager class uses two instances of the StringContactMap to keep track of its contacts. One keyed by phone number and another keyed by name.
The InteractivePhoneBook class has an instance of the ContactManager class. It offers a console user interface which allows the user to interact with the ContactManager and, thus, the StringContactMap hashmap implementation.

The CSV files can be read into the ContactManager using the InteractivePhoneBook UI.

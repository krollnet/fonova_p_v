#include <iostream>
#include <string>                                          //чтоб шаблоны работали

template<typename T>          //шаблонный класс List               ,тк содержит Node, тип которой мы не знаем 
class List {
public:
	List();
	~List();

	void push_back(T value);


private:

	//шаблонный класс Node
	template <typename T>
	class Node {
	public:
		//поля класса Node
		Node *pNext;
		T value;                                  //значения могут быть разных типов,поэтому делаем шаблонный тип
		// конструктор Node
		Node(T value=T(), Node *pNext = nullptr)  //аргументамтприсваиваются значения по умолчанию, если дальше ничего нет
			: value(value)
			, pNext(pNext){}
	};

	//поля класса List
	int size;
	Node<T> *head;

};

template<typename T>
List<T>::List() 
{
	size = 0;
	head = nullptr;
}

template <typename T>
List<T>::~List() 
{

}

template<typename T>
void List<T>::push_back(T value)
{
	if (head == nullptr){
		head = new Node<T>(value); //создаем новый элемент(выделяем память под него) типа Node и передаем ему в конструктор данные 
	}
	else {
		Node<T> *current = head;                                       // возможно должно быть "= this->head"
		while (current->pNext != nullptr)
		{
			currnet = current->pNext;
		}
	}
}





int main() {
	List<int> lst;
	lst.push_back(5);
	lst.push_back(10);

	
	return 0;
}
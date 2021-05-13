#include<vector>
using std::vector;

template <class E> 
class CrudRepository
{
public:
	virtual void add_Car(E e) = 0;
	virtual void delete_Car(E e) = 0;
	virtual void update_km(E e, double km) = 0;
	virtual void update_price(E e, double price) = 0;
	virtual void update_Car(E e, int index) = 0;
	virtual void show_all() = 0;
	virtual vector<E> get_all()=0;
	virtual ~CrudRepository() {};
};
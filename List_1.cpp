#include <iostream>
#include "list.cpp"


class Garden {
public:
    Garden(int size) : max_size(size) {
    }
    void plant(int lifespan) {
        if (list2.max_size() > list2.size())
            list2.Add(lifespan);
    
    
    }
    void Print()
    {
        list2.iterator = list2.begin();
        while ((*list2.iterator).next != nullptr)
        {
            if((*list2.iterator).data < 0)
                std::cout << "0" << " ";
            else
            {
                std::cout << (*list2.iterator).data << " ";
            }
            list2.iterator = (*list2.iterator).next;
        }
        if ((*list2.iterator).data < 0)
            std::cout << "0" << std::endl;
        else
            std::cout << (*list2.iterator).data << std::endl;
        
      //  list2.iterator = (*list2.iterator).next;
        
       
    }
    void agePlants() {
        list2.iterator = list2.begin();
        if (list2.size() != 0)
        {
            while ((*list2.iterator).next != nullptr)
            {
                list2.iterator++;

            }
            (*list2.iterator).data--;
        }
     
    }
    int get_current_size() { return list2.size(); }
    int get_max_size() { return max_size; }
    bool garden__check_died()
    {
        int count = 0;
        list2.iterator = list2.begin();
        while ((*list2.iterator).next != nullptr)
        {
            
            if ((*list2.iterator).data <= 0) count++;
            list2.iterator = (*list2.iterator).next;
        }
        if ((*list2.iterator).data <= 0) count++;
        if (count == list2.size())
        {
            std::cout << "end  ";
            return true;
        }
        return false;

    }


private:
    int max_size;
    int current_size;
    DigitalList<int> list2 = DigitalList<int>();
};
void simulate()
{
    int size;
    std::cout << "Enter the size of the garden: ";
    std::cin >> size;
    int count_day;
    std::cout << "Enter count days: ";
    std::cin >> count_day;
    Garden garden(size);
    bool b = true;
    // заполняем грядку 
    while (b) {
        if (garden.get_max_size() > garden.get_current_size())
        {
            int idx, lifespan;
            std::cout << "Enter lifespan of the plant to plant (or -1 to exit): ";
            std::cin >> lifespan;
            if (lifespan != -1)
                garden.plant(lifespan);
            else
                b = false;
        }
        else
        {
            b = false;
        }

    }
    int i = 1;
    //симуляция
    while (i <= count_day) {
        // стареит 
        garden.agePlants();
        std::cout << "day_" << i << ":";
        garden.Print();
        if (garden.garden__check_died()) break;

        i++;


    }

    
}

int main()
{
    simulate();


	/*DigitalList<int> list = DigitalList<int>();
	list.Add(332);
	list.Add(2);
    list.Print();*/

	


	

  
}


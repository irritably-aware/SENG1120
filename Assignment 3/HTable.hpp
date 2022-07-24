/*  Wei Chen C3355372
    Assignment 3
    11/06/2022
    HTable.h: header implementation for Hash Table class
*/
                        //pre: none
template<typename T>    //post: HTable created and array variable initialised to length 10000
HTable<T>::HTable(){
    c = Cities("default", 1);
    for(int i=0; i<TABLE_SIZE; i++){table[i]=c;}
}
                        //pre: none
template<typename T>    //post: data is all on stack, nice!
HTable<T>::~HTable(){}

                        //pre: HTable initialised
template<typename T>    //post: writes data to set location
void HTable<T>::add(T& newData){
    table[hashfun(newData)]=newData;             //(megamind)no buckets?
}
                        //pre: HTable initialised
template<typename T>    //post: remove the data in matching position
void HTable<T>::remove(T& key){
    table[hashfun(key)]=c;
}
                        //pre: HTable initialised, given input T& data
template <typename T>   //post: provide a interger from input data
int HTable<T>::hashfun(const T& value){
    int position = 0;
    string temp = value.get_name();

    for(int i=0; i<(int)temp.length(); i++){
        position+= (i+1) * (i+1) * temp.at(i);
    }
    return position % TABLE_SIZE;
}
                        //pre: HTable initialised
template <typename T>   //post: prints all non-default data
void HTable<T>::print(std::ostream& out){
    for(int i=0; i<TABLE_SIZE; i++){
        if(table[i].get_population()!=c.get_population()){
            out<<table[i]<<"    ";
        }
    }
}
                        //pre: HTable initialised
template <typename T>   //post: returns total population of non-default cities
int HTable<T>::calculateTotalPop(){
    int totalPop=0;
    for(int i=0; i<TABLE_SIZE; i++){
        if(table[i].get_population()!=c.get_population()){
            totalPop+=table[i].get_population();
        }
    }
    return totalPop;
}
                        //pre: HTable initialised
template <typename T>   //post: returns population of non-default cities w/ population greater than lim
int HTable<T>::calculatePopGreaterThan(int lim){
    int totalPop=0;
    for(int i=0; i<TABLE_SIZE; i++){
        if(table[i].get_population()!=c.get_population()){
            if(table[i].get_population()>lim){
                totalPop+=table[i].get_population();
            }
            
        }
    }
    return totalPop;
}
                        //pre: HTable initialised
template <typename T>   //post: returns ostream with all cities data in htable
std::ostream& operator << (std::ostream& out, HTable<T>& h){
    h.print(out);
    return out;
}
//done! !!! !!! !
//turns out not done :(
    //done(for the last time)
table::table(){
    myTable = NULL;
};



table::~table(){
    delete myTable;
}



int table::init(int tblSize){
    int flag = 0;
    head = new node[tblSize];
    return flag;
}



int table::add(node * toAdd){
    int flag = 0;
    //need logic to add to correct head hash
    head.add(toAdd);
    return flag;
}

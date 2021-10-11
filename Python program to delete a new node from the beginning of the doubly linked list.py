#Represent a node of doubly linked list    
class Node:    
    def __init__(self,data):    
        self.data = data;    
        self.previous = None;    
        self.next = None;    
            
class DeleteStart:    
    #Represent the head and tail of the doubly linked list    
    def __init__(self):    
        self.head = None;    
        self.tail = None;    
            
    #addNode() will add a node to the list    
    def addNode(self, data):    
        #Create a new node    
        newNode = Node(data);    
            
        #If list is empty    
        if(self.head == None):    
            #Both head and tail will point to newNode    
            self.head = self.tail = newNode;    
            #head's previous will point to None    
            self.head.previous = None;    
            #tail's next will point to None, as it is the last node of the list    
            self.tail.next = None;    
        else:    
            #newNode will be added after tail such that tail's next will point to newNode    
            self.tail.next = newNode;    
            #newNode's previous will point to tail    
            newNode.previous = self.tail;    
            #newNode will become new tail    
            self.tail = newNode;    
            #As it is last node, tail's next will point to None    
            self.tail.next = None;    
                
    #deleteFromStart() will delete a node from the beginning of the list    
    def deleteFromStart(self):    
        #Checks whether list is empty    
        if(self.head == None):    
            return;    
        else:    
            #Checks whether the list contains only one element    
            if(self.head != self.tail):    
                #head will point to next node in the list    
                self.head = self.head.next;    
                #Previous node to current head will be made None    
                self.head.previous = None;    
                    
            #If the list contains only one element     
            #then, it will remove the node, and now both head and tail will point to None    
    
            else:    
                self.head = self.tail = None;    
                    
    #display() will print out the nodes of the list    
    def display(self):    
        #Node current will point to head    
        current = self.head;    
        if(self.head == None):    
            print("List is empty");    
            return;    
        while(current != None):    
            #Prints each node by incrementing pointer.    
            print(current.data),    
            current = current.next;    
        print();    
           
dList = DeleteStart();    
#Add nodes to the list    
dList.addNode(1);    
dList.addNode(2);    
dList.addNode(3);    
dList.addNode(4);    
dList.addNode(5);    
     
#Printing original list    
print("Original List: ");    
dList.display();    
while(dList.head != None):    
    dList.deleteFromStart();    
    #Printing updated list    
    print("Updated List: ");    
    dList.display();      

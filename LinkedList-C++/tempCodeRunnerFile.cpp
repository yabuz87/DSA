int peak()
    {
        if(front==-1)
        {
            cout<<"queue is empty\n";
            return -1;
        }
        else {
            return num[front];
        }
    }
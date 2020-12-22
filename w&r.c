void reader(int i)
{
    message rmsg;
       while(ture) {
           rmsg = i;
           send (readrequest,rmsg);
           receive (mbox[i],rmsg);
           READUNIT ();
           rmsg = i;
           send (finished,rmsg);
       }
}



void writer(int j)
{
    message rmsg;
       while(ture) {
           rmsg = j;
           send (writerequest,rmsg);
           receive (mbox[j],rmsg);
           READUNIT ();
           rmsg = j;
           send (finished,rmsg);
       }
}



void controller()
{
    int count = 100;//100 equals to n+1(number of readers+1)
    while(ture) {
        if(count > 0) {
            if(!empty(finished)) {
                receive(finished,msg);
                count++;
            }
            else if(!empty(readrequest)) {
                receive(readrequest,msg);
                count--；
                send(msg.id,"OK");
            }
            else if(!empty(writerequest)) {
                receive(writerequest,msg);
                writer.id=msg.id;
                count=count-100;
                
            }
        }
        if(count == 0) {
            send(writer.id,"OK");
            receive(finished,msg);
            count = 100;
        }
        while(count < 0) {
            receive(finished,msg);
            count++;
        }
    }
}
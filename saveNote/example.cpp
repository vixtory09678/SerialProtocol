#include "mbed.h"
#include "SaveMelody.h"

SaveMelody save1;
SaveMelody save2;

int main()
{
    for(int i = 0 ; i< 20;i++){
        save1.addNote(i);
    }
    printf("size is %d\n",save1.sizeNote());
    printf("row is %d\n",save1.getSizeRow());
    printf("column is %d\n",save1.getSizeColumn(save1.getSizeRow()));

    printf("is empty %s\n",save2.isEmpty()?"empty":"have data");
    save2.copy(save1.getInstance());
    printf("is empty %s\n",save2.isEmpty()?"empty":"have data");
    printf("\n\n");
    printf("size is %d\n",save2.sizeNote());
    printf("row is %d\n",save2.getSizeRow());
    printf("column is %d\n",save2.getSizeColumn(save2.getSizeRow()));
    return 0;
}

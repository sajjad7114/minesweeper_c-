#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "qmessagebox.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QMouseEvent>
int i1,j1;
int sow[8][8];
int os[8][8]={0};
int table[8][8];
int openwhole(int i,int j);
void save(){
    int i,j,count=1,a,b,c,d,m,p;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++){
            sow[i][j]=0; os[i][j]=0;
    }
    int table2[8][8];
    for (i=0;i<8;i++)
        for(j=0;j<8;j++){
            sow[i][j]=0;
            os[i][j]=0;
    }
        for(c=0;c<=7;c++)
            for(d=0;d<=7;d++)
                table[c][d]=0;
        srand(time(0)); //takes bombs
        while(count<=10){
            int i=rand()%8;
            int j=rand()%8;
            if (table[i][j]==0)
                count++;
            table[i][j]=9;
        }
 for(a=0;a<=7;a++){ for(b=0;b<=7;b++){ if (table[a][b]!=9){  //calculates the number of bombs arround
   if (a==0&&b==7)  table2[0][7]= (table[1][6]+table[0][6]+table[1][7])/9;
 else if (a==0&&b==0)  table2[0][0]= (table[0][1]+table[1][0]+table[1][1])/9;
 else if (a==7&&b==7)  table2[7][7]= (table[6][7]+table[7][6]+table[6][6])/9;
 else if (a==7&&b==0)  table2[7][0]= (table[6][0]+table[6][1]+table[7][1])/9;
 else if (a==0)  table2[0][b]= (table[0][b-1]+table[0][b+1]+table[1][b]+table[1][b-1]+table[1][b+1])/9;
 else if (b==0)  table2[a][0]= (table[a][1]+table[a-1][1]+table[a+1][1]+table[a-1][0]+table[a+1][0])/9;
 else if (a==7) table2[7][b]= (table[6][b]+table[6][b-1]+table[6][b+1]+table[7][b-1]+table[7][b+1])/9;
 else if (b==7) table2[a][7]= (table[a][6]+table[a-1][6]+table[a+1][6]+table[a-1][7]+table[a+1][7])/9;
 else 	table2[a][b]= (table[a-1][b-1]+table[a][b-1]+table[a+1][b-1]+table[a-1][b]+table[a+1][b]+table[a-1][b+1]+table[a][b+1]+table[a+1][b+1])/9;
    }}}
     for(m=0;m<8;m++) {
        for(p=0;p<8;p++)
            if(table[m][p]!=9)
                table[m][p]=table2[m][p];
        }
}

void open(int i,int j){     //open the array
    int a,b;
    sow[i][j]=1;
if(table[i][j]==0){
    os[i][j]=openwhole(i,j);
    for(a=0;a<8;a++) for(b=0;b<8;b++) if(table[a][b]==0&&sow[a][b]==1&&os[a][b]==0) open(a,b); //for opening the whole of 0
}
}
int openwhole(int i,int j){  //opens when the number is 0
     if(i==0&&j==0) {sow[1][1]=1; sow[0][1]=1; sow[1][0]=1;}
else if(i==7&&j==0) {sow[7][1]=1; sow[6][1]=1; sow[6][0]=1;}
else if(i==7&&j==7) {sow[7][6]=1; sow[6][7]=1; sow[6][6]=1;}
else if(i==0&&j==7) {sow[0][6]=1; sow[1][7]=1; sow[1][6]=1;}
else if(i==0) {sow[0][j+1]=1; sow[0][j-1]=1; sow[1][j]=1; sow[1][j-1]=1; sow[1][j+1]=1;}
else if(i==7) {sow[7][j+1]=1; sow[7][j-1]=1; sow[6][j]=1; sow[6][j-1]=1; sow[6][j+1]=1;}
else if(j==0) {sow[i+1][0]=1; sow[i-1][0]=1; sow[i][1]=1; sow[i+1][1]=1; sow[i-1][1]=1;}
else if(j==7) {sow[i+1][7]=1; sow[i-1][7]=1; sow[i][6]=1; sow[i+1][6]=1; sow[i-1][6]=1;}
else {sow[i][j-1]=1; sow[i+1][j-1]=1; sow[i-1][j]=1;sow[i-1][j-1]=1; sow[i+1][j]=1; sow[i-1][j+1]=1; sow[i][j+1]=1; sow[i+1][j+1]=1;}
return 1;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    save();
    int i,j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++){
            os[i][j]=0; sow[i][j]=0;
        }
    }
void MainWindow::on_pushButton_65_clicked()
{
    int i,j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++){
            os[i][j]=0; sow[i][j]=0;
        }
    save();
    ui->pushButton->setEnabled(1);
    ui->pushButton_2->setEnabled(1);
    ui->pushButton_3->setEnabled(1);
    ui->pushButton_4->setEnabled(1);
    ui->pushButton_5->setEnabled(1);
    ui->pushButton_6->setEnabled(1);
    ui->pushButton_7->setEnabled(1);
    ui->pushButton_8->setEnabled(1);
    ui->pushButton_9->setEnabled(1);
    ui->pushButton_10->setEnabled(1);
    ui->pushButton_11->setEnabled(1);
    ui->pushButton_12->setEnabled(1);
    ui->pushButton_13->setEnabled(1);
    ui->pushButton_14->setEnabled(1);
    ui->pushButton_15->setEnabled(1);
    ui->pushButton_16->setEnabled(1);
    ui->pushButton_17->setEnabled(1);
    ui->pushButton_18->setEnabled(1);
    ui->pushButton_19->setEnabled(1);
    ui->pushButton_20->setEnabled(1);
    ui->pushButton_21->setEnabled(1);
    ui->pushButton_22->setEnabled(1);
    ui->pushButton_23->setEnabled(1);
    ui->pushButton_24->setEnabled(1);
    ui->pushButton_25->setEnabled(1);
    ui->pushButton_26->setEnabled(1);
    ui->pushButton_27->setEnabled(1);
    ui->pushButton_28->setEnabled(1);
    ui->pushButton_29->setEnabled(1);
    ui->pushButton_30->setEnabled(1);
    ui->pushButton_31->setEnabled(1);
    ui->pushButton_32->setEnabled(1);
    ui->pushButton_33->setEnabled(1);
    ui->pushButton_34->setEnabled(1);
    ui->pushButton_35->setEnabled(1);
    ui->pushButton_36->setEnabled(1);
    ui->pushButton_37->setEnabled(1);
    ui->pushButton_38->setEnabled(1);
    ui->pushButton_39->setEnabled(1);
    ui->pushButton_40->setEnabled(1);
    ui->pushButton_41->setEnabled(1);
    ui->pushButton_42->setEnabled(1);
    ui->pushButton_43->setEnabled(1);
    ui->pushButton_44->setEnabled(1);
    ui->pushButton_45->setEnabled(1);
    ui->pushButton_46->setEnabled(1);
    ui->pushButton_47->setEnabled(1);
    ui->pushButton_48->setEnabled(1);
    ui->pushButton_49->setEnabled(1);
    ui->pushButton_50->setEnabled(1);
    ui->pushButton_51->setEnabled(1);
    ui->pushButton_52->setEnabled(1);
    ui->pushButton_53->setEnabled(1);
    ui->pushButton_54->setEnabled(1);
    ui->pushButton_55->setEnabled(1);
    ui->pushButton_56->setEnabled(1);
    ui->pushButton_57->setEnabled(1);
    ui->pushButton_58->setEnabled(1);
    ui->pushButton_59->setEnabled(1);
    ui->pushButton_60->setEnabled(1);
    ui->pushButton_61->setEnabled(1);
    ui->pushButton_62->setEnabled(1);
    ui->pushButton_63->setEnabled(1);
    ui->pushButton_64->setEnabled(1);
    ui->pushButton->setText(" ");
    ui->pushButton_2->setText(" ");
    ui->pushButton_3->setText(" ");
    ui->pushButton_4->setText(" ");
    ui->pushButton_5->setText(" ");
    ui->pushButton_6->setText(" ");
    ui->pushButton_7->setText(" ");
    ui->pushButton_8->setText(" ");
    ui->pushButton_9->setText(" ");
    ui->pushButton_10->setText(" ");
    ui->pushButton_11->setText(" ");
    ui->pushButton_12->setText(" ");
    ui->pushButton_13->setText(" ");
    ui->pushButton_14->setText(" ");
    ui->pushButton_15->setText(" ");
    ui->pushButton_16->setText(" ");
    ui->pushButton_17->setText(" ");
    ui->pushButton_18->setText(" ");
    ui->pushButton_19->setText(" ");
    ui->pushButton_20->setText(" ");
    ui->pushButton_21->setText(" ");
    ui->pushButton_22->setText(" ");
    ui->pushButton_23->setText(" ");
    ui->pushButton_24->setText(" ");
    ui->pushButton_25->setText(" ");
    ui->pushButton_26->setText(" ");
    ui->pushButton_27->setText(" ");
    ui->pushButton_28->setText(" ");
    ui->pushButton_29->setText(" ");
    ui->pushButton_30->setText(" ");
    ui->pushButton_31->setText(" ");
    ui->pushButton_32->setText(" ");
    ui->pushButton_33->setText(" ");
    ui->pushButton_34->setText(" ");
    ui->pushButton_35->setText(" ");
    ui->pushButton_36->setText(" ");
    ui->pushButton_37->setText(" ");
    ui->pushButton_38->setText(" ");
    ui->pushButton_39->setText(" ");
    ui->pushButton_40->setText(" ");
    ui->pushButton_41->setText(" ");
    ui->pushButton_42->setText(" ");
    ui->pushButton_43->setText(" ");
    ui->pushButton_44->setText(" ");
    ui->pushButton_45->setText(" ");
    ui->pushButton_46->setText(" ");
    ui->pushButton_47->setText(" ");
    ui->pushButton_48->setText(" ");
    ui->pushButton_49->setText(" ");
    ui->pushButton_50->setText(" ");
    ui->pushButton_51->setText(" ");
    ui->pushButton_52->setText(" ");
    ui->pushButton_53->setText(" ");
    ui->pushButton_54->setText(" ");
    ui->pushButton_55->setText(" ");
    ui->pushButton_56->setText(" ");
    ui->pushButton_57->setText(" ");
    ui->pushButton_58->setText(" ");
    ui->pushButton_59->setText(" ");
    ui->pushButton_60->setText(" ");
    ui->pushButton_61->setText(" ");
    ui->pushButton_62->setText(" ");
    ui->pushButton_64->setText(" ");
    ui->pushButton_63->setText(" ");
}
void MainWindow::lost(){
    int i,j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++){
            if(table[i][j]==9) sow[i][j]=1;
        }
    QMessageBox msgBox;
    msgBox.setText("Sorry! You lost! :D");
    msgBox.exec();
    msgBox.setText("You can restart if you want");
    msgBox.exec();
    ui->pushButton->setEnabled(0);
    ui->pushButton_2->setEnabled(0);
    ui->pushButton_3->setEnabled(0);
    ui->pushButton_4->setEnabled(0);
    ui->pushButton_5->setEnabled(0);
    ui->pushButton_6->setEnabled(0);
    ui->pushButton_7->setEnabled(0);
    ui->pushButton_8->setEnabled(0);
    ui->pushButton_9->setEnabled(0);
    ui->pushButton_10->setEnabled(0);
    ui->pushButton_11->setEnabled(0);
    ui->pushButton_12->setEnabled(0);
    ui->pushButton_13->setEnabled(0);
    ui->pushButton_14->setEnabled(0);
    ui->pushButton_15->setEnabled(0);
    ui->pushButton_16->setEnabled(0);
    ui->pushButton_17->setEnabled(0);
    ui->pushButton_18->setEnabled(0);
    ui->pushButton_19->setEnabled(0);
    ui->pushButton_20->setEnabled(0);
    ui->pushButton_21->setEnabled(0);
    ui->pushButton_22->setEnabled(0);
    ui->pushButton_23->setEnabled(0);
    ui->pushButton_24->setEnabled(0);
    ui->pushButton_25->setEnabled(0);
    ui->pushButton_26->setEnabled(0);
    ui->pushButton_27->setEnabled(0);
    ui->pushButton_28->setEnabled(0);
    ui->pushButton_29->setEnabled(0);
    ui->pushButton_30->setEnabled(0);
    ui->pushButton_31->setEnabled(0);
    ui->pushButton_32->setEnabled(0);
    ui->pushButton_33->setEnabled(0);
    ui->pushButton_34->setEnabled(0);
    ui->pushButton_35->setEnabled(0);
    ui->pushButton_36->setEnabled(0);
    ui->pushButton_37->setEnabled(0);
    ui->pushButton_38->setEnabled(0);
    ui->pushButton_39->setEnabled(0);
    ui->pushButton_40->setEnabled(0);
    ui->pushButton_41->setEnabled(0);
    ui->pushButton_42->setEnabled(0);
    ui->pushButton_43->setEnabled(0);
    ui->pushButton_44->setEnabled(0);
    ui->pushButton_45->setEnabled(0);
    ui->pushButton_46->setEnabled(0);
    ui->pushButton_47->setEnabled(0);
    ui->pushButton_48->setEnabled(0);
    ui->pushButton_49->setEnabled(0);
    ui->pushButton_50->setEnabled(0);
    ui->pushButton_51->setEnabled(0);
    ui->pushButton_52->setEnabled(0);
    ui->pushButton_53->setEnabled(0);
    ui->pushButton_54->setEnabled(0);
    ui->pushButton_55->setEnabled(0);
    ui->pushButton_56->setEnabled(0);
    ui->pushButton_57->setEnabled(0);
    ui->pushButton_58->setEnabled(0);
    ui->pushButton_59->setEnabled(0);
    ui->pushButton_60->setEnabled(0);
    ui->pushButton_61->setEnabled(0);
    ui->pushButton_62->setEnabled(0);
    ui->pushButton_63->setEnabled(0);
    ui->pushButton_64->setEnabled(0);
}
void MainWindow::win(){
    int i,j,w=1;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(table[i][j]<9&&sow[i][j]==1) w=w*1;
            else if(table[i][j]==9&&sow[i][j]!=1) w=w*1;
            else w=0;
                }}
    if(w==1){
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if(table[i][j]==9) sow[i][j]=2;}}
        QMessageBox msgBox;
        msgBox.setText("You win! :D");
        msgBox.exec();
        msgBox.setText("You can restart if you want");
        msgBox.exec();
        ui->pushButton->setEnabled(0);
        ui->pushButton_2->setEnabled(0);
        ui->pushButton_3->setEnabled(0);
        ui->pushButton_4->setEnabled(0);
        ui->pushButton_5->setEnabled(0);
        ui->pushButton_6->setEnabled(0);
        ui->pushButton_7->setEnabled(0);
        ui->pushButton_8->setEnabled(0);
        ui->pushButton_9->setEnabled(0);
        ui->pushButton_10->setEnabled(0);
        ui->pushButton_11->setEnabled(0);
        ui->pushButton_12->setEnabled(0);
        ui->pushButton_13->setEnabled(0);
        ui->pushButton_14->setEnabled(0);
        ui->pushButton_15->setEnabled(0);
        ui->pushButton_16->setEnabled(0);
        ui->pushButton_17->setEnabled(0);
        ui->pushButton_18->setEnabled(0);
        ui->pushButton_19->setEnabled(0);
        ui->pushButton_20->setEnabled(0);
        ui->pushButton_21->setEnabled(0);
        ui->pushButton_22->setEnabled(0);
        ui->pushButton_23->setEnabled(0);
        ui->pushButton_24->setEnabled(0);
        ui->pushButton_25->setEnabled(0);
        ui->pushButton_26->setEnabled(0);
        ui->pushButton_27->setEnabled(0);
        ui->pushButton_28->setEnabled(0);
        ui->pushButton_29->setEnabled(0);
        ui->pushButton_30->setEnabled(0);
        ui->pushButton_31->setEnabled(0);
        ui->pushButton_32->setEnabled(0);
        ui->pushButton_33->setEnabled(0);
        ui->pushButton_34->setEnabled(0);
        ui->pushButton_35->setEnabled(0);
        ui->pushButton_36->setEnabled(0);
        ui->pushButton_37->setEnabled(0);
        ui->pushButton_38->setEnabled(0);
        ui->pushButton_39->setEnabled(0);
        ui->pushButton_40->setEnabled(0);
        ui->pushButton_41->setEnabled(0);
        ui->pushButton_42->setEnabled(0);
        ui->pushButton_43->setEnabled(0);
        ui->pushButton_44->setEnabled(0);
        ui->pushButton_45->setEnabled(0);
        ui->pushButton_46->setEnabled(0);
        ui->pushButton_47->setEnabled(0);
        ui->pushButton_48->setEnabled(0);
        ui->pushButton_49->setEnabled(0);
        ui->pushButton_50->setEnabled(0);
        ui->pushButton_51->setEnabled(0);
        ui->pushButton_52->setEnabled(0);
        ui->pushButton_53->setEnabled(0);
        ui->pushButton_54->setEnabled(0);
        ui->pushButton_55->setEnabled(0);
        ui->pushButton_56->setEnabled(0);
        ui->pushButton_57->setEnabled(0);
        ui->pushButton_58->setEnabled(0);
        ui->pushButton_59->setEnabled(0);
        ui->pushButton_60->setEnabled(0);
        ui->pushButton_61->setEnabled(0);
        ui->pushButton_62->setEnabled(0);
        ui->pushButton_63->setEnabled(0);
        ui->pushButton_64->setEnabled(0);
    }
}
void MainWindow::bazi(){
    if(sow[0][0]==1){
        if(table[0][0]==0) ui->pushButton->setText("-");
        if(table[0][0]==1) ui->pushButton->setText("1");
        if(table[0][0]==2) ui->pushButton->setText("2");
        if(table[0][0]==3) ui->pushButton->setText("3");
        if(table[0][0]==4) ui->pushButton->setText("4");
        if(table[0][0]==5) ui->pushButton->setText("5");
        if(table[0][0]==6) ui->pushButton->setText("6");
        if(table[0][0]==7) ui->pushButton->setText("7");
        if(table[0][0]==8) ui->pushButton->setText("8");
        if(table[0][0]==9) ui->pushButton->setText("*");
    }
    if(sow[0][0]==2) ui->pushButton->setText("^");
    if(sow[0][0]==0) ui->pushButton->setText(" ");
    if(sow[0][1]==1){
        if(table[0][1]==0) ui->pushButton_2->setText("-");
        if(table[0][1]==1) ui->pushButton_2->setText("1");
        if(table[0][1]==2) ui->pushButton_2->setText("2");
        if(table[0][1]==3) ui->pushButton_2->setText("3");
        if(table[0][1]==4) ui->pushButton_2->setText("4");
        if(table[0][1]==5) ui->pushButton_2->setText("5");
        if(table[0][1]==6) ui->pushButton_2->setText("6");
        if(table[0][1]==7) ui->pushButton_2->setText("7");
        if(table[0][1]==8) ui->pushButton_2->setText("8");
        if(table[0][1]==9) ui->pushButton_2->setText("*");
}
    if(sow[0][1]==2) ui->pushButton_2->setText("^");
    if(sow[0][1]==0) ui->pushButton_2->setText(" ");
    if(sow[0][2]==1){
        if(table[0][2]==0) ui->pushButton_3->setText("-");
        if(table[0][2]==1) ui->pushButton_3->setText("1");
        if(table[0][2]==2) ui->pushButton_3->setText("2");
        if(table[0][2]==3) ui->pushButton_3->setText("3");
        if(table[0][2]==4) ui->pushButton_3->setText("4");
        if(table[0][2]==5) ui->pushButton_3->setText("5");
        if(table[0][2]==6) ui->pushButton_3->setText("6");
        if(table[0][2]==7) ui->pushButton_3->setText("7");
        if(table[0][2]==8) ui->pushButton_3->setText("8");
        if(table[0][2]==9) ui->pushButton_3->setText("*");
}
    if(sow[0][2]==2) ui->pushButton_3->setText("^");
    if(sow[0][2]==0) ui->pushButton_3->setText(" ");
    if(sow[0][3]==1){
        if(table[0][3]==0) ui->pushButton_4->setText("-");
        if(table[0][3]==1) ui->pushButton_4->setText("1");
        if(table[0][3]==2) ui->pushButton_4->setText("2");
        if(table[0][3]==3) ui->pushButton_4->setText("3");
        if(table[0][3]==4) ui->pushButton_4->setText("4");
        if(table[0][3]==5) ui->pushButton_4->setText("5");
        if(table[0][3]==6) ui->pushButton_4->setText("6");
        if(table[0][3]==7) ui->pushButton_4->setText("7");
        if(table[0][3]==8) ui->pushButton_4->setText("8");
        if(table[0][3]==9) ui->pushButton_4->setText("*");
}
    if(sow[0][3]==2) ui->pushButton_4->setText("^");
    if(sow[0][3]==0) ui->pushButton_4->setText(" ");
    if(sow[0][4]==1){
        if(table[0][4]==0) ui->pushButton_5->setText("-");
        if(table[0][4]==1) ui->pushButton_5->setText("1");
        if(table[0][4]==2) ui->pushButton_5->setText("2");
        if(table[0][4]==3) ui->pushButton_5->setText("3");
        if(table[0][4]==4) ui->pushButton_5->setText("4");
        if(table[0][4]==5) ui->pushButton_5->setText("5");
        if(table[0][4]==6) ui->pushButton_5->setText("6");
        if(table[0][4]==7) ui->pushButton_5->setText("7");
        if(table[0][4]==8) ui->pushButton_5->setText("8");
        if(table[0][4]==9) ui->pushButton_5->setText("*");
}
    if(sow[0][4]==2) ui->pushButton_5->setText("^");
    if(sow[0][4]==0) ui->pushButton_5->setText(" ");
    if(sow[0][5]==1){
        if(table[0][5]==0) ui->pushButton_6->setText("-");
        if(table[0][5]==1) ui->pushButton_6->setText("1");
        if(table[0][5]==2) ui->pushButton_6->setText("2");
        if(table[0][5]==3) ui->pushButton_6->setText("3");
        if(table[0][5]==4) ui->pushButton_6->setText("4");
        if(table[0][5]==5) ui->pushButton_6->setText("5");
        if(table[0][5]==6) ui->pushButton_6->setText("6");
        if(table[0][5]==7) ui->pushButton_6->setText("7");
        if(table[0][5]==8) ui->pushButton_6->setText("8");
        if(table[0][5]==9) ui->pushButton_6->setText("*");
}
    if(sow[0][5]==2) ui->pushButton_6->setText("^");
    if(sow[0][5]==0) ui->pushButton_6->setText(" ");
    if(sow[0][6]==1){
        if(table[0][6]==0) ui->pushButton_7->setText("-");
        if(table[0][6]==1) ui->pushButton_7->setText("1");
        if(table[0][6]==2) ui->pushButton_7->setText("2");
        if(table[0][6]==3) ui->pushButton_7->setText("3");
        if(table[0][6]==4) ui->pushButton_7->setText("4");
        if(table[0][6]==5) ui->pushButton_7->setText("5");
        if(table[0][6]==6) ui->pushButton_7->setText("6");
        if(table[0][6]==7) ui->pushButton_7->setText("7");
        if(table[0][6]==8) ui->pushButton_7->setText("8");
        if(table[0][6]==9) ui->pushButton_7->setText("*");
}
    if(sow[0][6]==2) ui->pushButton_7->setText("^");
    if(sow[0][6]==0) ui->pushButton_7->setText(" ");
    if(sow[0][7]==1){
        if(table[0][7]==0) ui->pushButton_8->setText("-");
        if(table[0][7]==1) ui->pushButton_8->setText("1");
        if(table[0][7]==2) ui->pushButton_8->setText("2");
        if(table[0][7]==3) ui->pushButton_8->setText("3");
        if(table[0][7]==4) ui->pushButton_8->setText("4");
        if(table[0][7]==5) ui->pushButton_8->setText("5");
        if(table[0][7]==6) ui->pushButton_8->setText("6");
        if(table[0][7]==7) ui->pushButton_8->setText("7");
        if(table[0][7]==8) ui->pushButton_8->setText("8");
        if(table[0][7]==9) ui->pushButton_8->setText("*");
}
    if(sow[0][7]==2) ui->pushButton_8->setText("^");
    if(sow[0][7]==0) ui->pushButton_8->setText(" ");
    if(sow[1][0]==1){
        if(table[1][0]==0) ui->pushButton_13->setText("-");
        if(table[1][0]==1) ui->pushButton_13->setText("1");
        if(table[1][0]==2) ui->pushButton_13->setText("2");
        if(table[1][0]==3) ui->pushButton_13->setText("3");
        if(table[1][0]==4) ui->pushButton_13->setText("4");
        if(table[1][0]==5) ui->pushButton_13->setText("5");
        if(table[1][0]==6) ui->pushButton_13->setText("6");
        if(table[1][0]==7) ui->pushButton_13->setText("7");
        if(table[1][0]==8) ui->pushButton_13->setText("8");
        if(table[1][0]==9) ui->pushButton_13->setText("*");
}
    if(sow[1][0]==2) ui->pushButton_13->setText("^");
    if(sow[1][0]==0) ui->pushButton_13->setText(" ");
    if(sow[1][1]==1){
        if(table[1][1]==0) ui->pushButton_15->setText("-");
        if(table[1][1]==1) ui->pushButton_15->setText("1");
        if(table[1][1]==2) ui->pushButton_15->setText("2");
        if(table[1][1]==3) ui->pushButton_15->setText("3");
        if(table[1][1]==4) ui->pushButton_15->setText("4");
        if(table[1][1]==5) ui->pushButton_15->setText("5");
        if(table[1][1]==6) ui->pushButton_15->setText("6");
        if(table[1][1]==7) ui->pushButton_15->setText("7");
        if(table[1][1]==8) ui->pushButton_15->setText("8");
        if(table[1][1]==9) ui->pushButton_15->setText("*");
}
    if(sow[1][1]==2) ui->pushButton_15->setText("^");
    if(sow[1][1]==0) ui->pushButton_15->setText(" ");
    if(sow[1][2]==1){
        if(table[1][2]==0) ui->pushButton_9->setText("-");
        if(table[1][2]==1) ui->pushButton_9->setText("1");
        if(table[1][2]==2) ui->pushButton_9->setText("2");
        if(table[1][2]==3) ui->pushButton_9->setText("3");
        if(table[1][2]==4) ui->pushButton_9->setText("4");
        if(table[1][2]==5) ui->pushButton_9->setText("5");
        if(table[1][2]==6) ui->pushButton_9->setText("6");
        if(table[1][2]==7) ui->pushButton_9->setText("7");
        if(table[1][2]==8) ui->pushButton_9->setText("8");
        if(table[1][2]==9) ui->pushButton_9->setText("*");
}
    if(sow[1][2]==2) ui->pushButton_9->setText("^");
    if(sow[1][2]==0) ui->pushButton_9->setText(" ");
    if(sow[1][3]==1){
        if(table[1][3]==0) ui->pushButton_11->setText("-");
        if(table[1][3]==1) ui->pushButton_11->setText("1");
        if(table[1][3]==2) ui->pushButton_11->setText("2");
        if(table[1][3]==3) ui->pushButton_11->setText("3");
        if(table[1][3]==4) ui->pushButton_11->setText("4");
        if(table[1][3]==5) ui->pushButton_11->setText("5");
        if(table[1][3]==6) ui->pushButton_11->setText("6");
        if(table[1][3]==7) ui->pushButton_11->setText("7");
        if(table[1][3]==8) ui->pushButton_11->setText("8");
        if(table[1][3]==9) ui->pushButton_11->setText("*");
}
    if(sow[1][3]==2) ui->pushButton_11->setText("^");
    if(sow[1][3]==0) ui->pushButton_11->setText(" ");
    if(sow[1][4]==1){
        if(table[1][4]==0) ui->pushButton_12->setText("-");
        if(table[1][4]==1) ui->pushButton_12->setText("1");
        if(table[1][4]==2) ui->pushButton_12->setText("2");
        if(table[1][4]==3) ui->pushButton_12->setText("3");
        if(table[1][4]==4) ui->pushButton_12->setText("4");
        if(table[1][4]==5) ui->pushButton_12->setText("5");
        if(table[1][4]==6) ui->pushButton_12->setText("6");
        if(table[1][4]==7) ui->pushButton_12->setText("7");
        if(table[1][4]==8) ui->pushButton_12->setText("8");
        if(table[1][4]==9) ui->pushButton_12->setText("*");
}
    if(sow[1][4]==2) ui->pushButton_12->setText("^");
    if(sow[1][4]==0) ui->pushButton_12->setText(" ");
    if(sow[1][5]==1){
        if(table[1][5]==0) ui->pushButton_16->setText("-");
        if(table[1][5]==1) ui->pushButton_16->setText("1");
        if(table[1][5]==2) ui->pushButton_16->setText("2");
        if(table[1][5]==3) ui->pushButton_16->setText("3");
        if(table[1][5]==4) ui->pushButton_16->setText("4");
        if(table[1][5]==5) ui->pushButton_16->setText("5");
        if(table[1][5]==6) ui->pushButton_16->setText("6");
        if(table[1][5]==7) ui->pushButton_16->setText("7");
        if(table[1][5]==8) ui->pushButton_16->setText("8");
        if(table[1][5]==9) ui->pushButton_16->setText("*");
}
    if(sow[1][5]==2) ui->pushButton_16->setText("^");
    if(sow[1][5]==0) ui->pushButton_16->setText(" ");
    if(sow[1][6]==1){
        if(table[1][6]==0) ui->pushButton_10->setText("-");
        if(table[1][6]==1) ui->pushButton_10->setText("1");
        if(table[1][6]==2) ui->pushButton_10->setText("2");
        if(table[1][6]==3) ui->pushButton_10->setText("3");
        if(table[1][6]==4) ui->pushButton_10->setText("4");
        if(table[1][6]==5) ui->pushButton_10->setText("5");
        if(table[1][6]==6) ui->pushButton_10->setText("6");
        if(table[1][6]==7) ui->pushButton_10->setText("7");
        if(table[1][6]==8) ui->pushButton_10->setText("8");
        if(table[1][6]==9) ui->pushButton_10->setText("*");
}
    if(sow[1][6]==2) ui->pushButton_10->setText("^");
    if(sow[1][6]==0) ui->pushButton_10->setText(" ");
    if(sow[1][7]==1){
        if(table[1][7]==0) ui->pushButton_14->setText("-");
        if(table[1][7]==1) ui->pushButton_14->setText("1");
        if(table[1][7]==2) ui->pushButton_14->setText("2");
        if(table[1][7]==3) ui->pushButton_14->setText("3");
        if(table[1][7]==4) ui->pushButton_14->setText("4");
        if(table[1][7]==5) ui->pushButton_14->setText("5");
        if(table[1][7]==6) ui->pushButton_14->setText("6");
        if(table[1][7]==7) ui->pushButton_14->setText("7");
        if(table[1][7]==8) ui->pushButton_14->setText("8");
        if(table[1][7]==9) ui->pushButton_14->setText("*");
}
    if(sow[1][7]==2) ui->pushButton_14->setText("^");
    if(sow[1][7]==0) ui->pushButton_14->setText(" ");
    if(sow[2][0]==1){
        if(table[2][0]==0) ui->pushButton_23->setText("-");
        if(table[2][0]==1) ui->pushButton_23->setText("1");
        if(table[2][0]==2) ui->pushButton_23->setText("2");
        if(table[2][0]==3) ui->pushButton_23->setText("3");
        if(table[2][0]==4) ui->pushButton_23->setText("4");
        if(table[2][0]==5) ui->pushButton_23->setText("5");
        if(table[2][0]==6) ui->pushButton_23->setText("6");
        if(table[2][0]==7) ui->pushButton_23->setText("7");
        if(table[2][0]==8) ui->pushButton_23->setText("8");
        if(table[2][0]==9) ui->pushButton_23->setText("*");
}
    if(sow[2][0]==2) ui->pushButton_23->setText("^");
    if(sow[2][0]==0) ui->pushButton_23->setText(" ");
    if(sow[2][1]==1){
        if(table[2][1]==0) ui->pushButton_30->setText("-");
        if(table[2][1]==1) ui->pushButton_30->setText("1");
        if(table[2][1]==2) ui->pushButton_30->setText("2");
        if(table[2][1]==3) ui->pushButton_30->setText("3");
        if(table[2][1]==4) ui->pushButton_30->setText("4");
        if(table[2][1]==5) ui->pushButton_30->setText("5");
        if(table[2][1]==6) ui->pushButton_30->setText("6");
        if(table[2][1]==7) ui->pushButton_30->setText("7");
        if(table[2][1]==8) ui->pushButton_30->setText("8");
        if(table[2][1]==9) ui->pushButton_30->setText("*");
}
    if(sow[2][1]==2) ui->pushButton_30->setText("^");
    if(sow[2][1]==0) ui->pushButton_30->setText(" ");
    if(sow[2][2]==1){
        if(table[2][2]==0) ui->pushButton_17->setText("-");
        if(table[2][2]==1) ui->pushButton_17->setText("1");
        if(table[2][2]==2) ui->pushButton_17->setText("2");
        if(table[2][2]==3) ui->pushButton_17->setText("3");
        if(table[2][2]==4) ui->pushButton_17->setText("4");
        if(table[2][2]==5) ui->pushButton_17->setText("5");
        if(table[2][2]==6) ui->pushButton_17->setText("6");
        if(table[2][2]==7) ui->pushButton_17->setText("7");
        if(table[2][2]==8) ui->pushButton_17->setText("8");
        if(table[2][2]==9) ui->pushButton_17->setText("*");
}
    if(sow[2][2]==2) ui->pushButton_17->setText("^");
    if(sow[2][2]==0) ui->pushButton_17->setText(" ");
    if(sow[2][3]==1){
        if(table[2][3]==0) ui->pushButton_19->setText("-");
        if(table[2][3]==1) ui->pushButton_19->setText("1");
        if(table[2][3]==2) ui->pushButton_19->setText("2");
        if(table[2][3]==3) ui->pushButton_19->setText("3");
        if(table[2][3]==4) ui->pushButton_19->setText("4");
        if(table[2][3]==5) ui->pushButton_19->setText("5");
        if(table[2][3]==6) ui->pushButton_19->setText("6");
        if(table[2][3]==7) ui->pushButton_19->setText("7");
        if(table[2][3]==8) ui->pushButton_19->setText("8");
        if(table[2][3]==9) ui->pushButton_19->setText("*");
}
    if(sow[2][3]==2) ui->pushButton_19->setText("^");
    if(sow[2][3]==0) ui->pushButton_19->setText(" ");
    if(sow[2][4]==1){
        if(table[2][4]==0) ui->pushButton_20->setText("-");
        if(table[2][4]==1) ui->pushButton_20->setText("1");
        if(table[2][4]==2) ui->pushButton_20->setText("2");
        if(table[2][4]==3) ui->pushButton_20->setText("3");
        if(table[2][4]==4) ui->pushButton_20->setText("4");
        if(table[2][4]==5) ui->pushButton_20->setText("5");
        if(table[2][4]==6) ui->pushButton_20->setText("6");
        if(table[2][4]==7) ui->pushButton_20->setText("7");
        if(table[2][4]==8) ui->pushButton_20->setText("8");
        if(table[2][4]==9) ui->pushButton_20->setText("*");
}
    if(sow[2][4]==2) ui->pushButton_20->setText("^");
    if(sow[2][4]==0) ui->pushButton_20->setText(" ");
    if(sow[2][5]==1){
        if(table[2][5]==0) ui->pushButton_32->setText("-");
        if(table[2][5]==1) ui->pushButton_32->setText("1");
        if(table[2][5]==2) ui->pushButton_32->setText("2");
        if(table[2][5]==3) ui->pushButton_32->setText("3");
        if(table[2][5]==4) ui->pushButton_32->setText("4");
        if(table[2][5]==5) ui->pushButton_32->setText("5");
        if(table[2][5]==6) ui->pushButton_32->setText("6");
        if(table[2][5]==7) ui->pushButton_32->setText("7");
        if(table[2][5]==8) ui->pushButton_32->setText("8");
        if(table[2][5]==9) ui->pushButton_32->setText("*");
}
    if(sow[2][5]==2) ui->pushButton_32->setText("^");
    if(sow[2][5]==0) ui->pushButton_32->setText(" ");
    if(sow[2][6]==1){
        if(table[2][6]==0) ui->pushButton_18->setText("-");
        if(table[2][6]==1) ui->pushButton_18->setText("1");
        if(table[2][6]==2) ui->pushButton_18->setText("2");
        if(table[2][6]==3) ui->pushButton_18->setText("3");
        if(table[2][6]==4) ui->pushButton_18->setText("4");
        if(table[2][6]==5) ui->pushButton_18->setText("5");
        if(table[2][6]==6) ui->pushButton_18->setText("6");
        if(table[2][6]==7) ui->pushButton_18->setText("7");
        if(table[2][6]==8) ui->pushButton_18->setText("8");
        if(table[2][6]==9) ui->pushButton_18->setText("*");
}
    if(sow[2][6]==2) ui->pushButton_18->setText("^");
    if(sow[2][6]==0) ui->pushButton_18->setText(" ");
    if(sow[2][7]==1){
        if(table[2][7]==0) ui->pushButton_25->setText("-");
        if(table[2][7]==1) ui->pushButton_25->setText("1");
        if(table[2][7]==2) ui->pushButton_25->setText("2");
        if(table[2][7]==3) ui->pushButton_25->setText("3");
        if(table[2][7]==4) ui->pushButton_25->setText("4");
        if(table[2][7]==5) ui->pushButton_25->setText("5");
        if(table[2][7]==6) ui->pushButton_25->setText("6");
        if(table[2][7]==7) ui->pushButton_25->setText("7");
        if(table[2][7]==8) ui->pushButton_25->setText("8");
        if(table[2][7]==9) ui->pushButton_25->setText("*");
}
    if(sow[2][7]==2) ui->pushButton_25->setText("^");
    if(sow[2][7]==0) ui->pushButton_25->setText(" ");
    if(sow[3][0]==1){
        if(table[3][0]==0) ui->pushButton_27->setText("-");
        if(table[3][0]==1) ui->pushButton_27->setText("1");
        if(table[3][0]==2) ui->pushButton_27->setText("2");
        if(table[3][0]==3) ui->pushButton_27->setText("3");
        if(table[3][0]==4) ui->pushButton_27->setText("4");
        if(table[3][0]==5) ui->pushButton_27->setText("5");
        if(table[3][0]==6) ui->pushButton_27->setText("6");
        if(table[3][0]==7) ui->pushButton_27->setText("7");
        if(table[3][0]==8) ui->pushButton_27->setText("8");
        if(table[3][0]==9) ui->pushButton_27->setText("*");
}
    if(sow[3][0]==2) ui->pushButton_27->setText("^");
    if(sow[3][0]==0) ui->pushButton_27->setText(" ");
    if(sow[3][1]==1){
        if(table[3][1]==0) ui->pushButton_28->setText("-");
        if(table[3][1]==1) ui->pushButton_28->setText("1");
        if(table[3][1]==2) ui->pushButton_28->setText("2");
        if(table[3][1]==3) ui->pushButton_28->setText("3");
        if(table[3][1]==4) ui->pushButton_28->setText("4");
        if(table[3][1]==5) ui->pushButton_28->setText("5");
        if(table[3][1]==6) ui->pushButton_28->setText("6");
        if(table[3][1]==7) ui->pushButton_28->setText("7");
        if(table[3][1]==8) ui->pushButton_28->setText("8");
        if(table[3][1]==9) ui->pushButton_28->setText("*");
}
    if(sow[3][1]==2) ui->pushButton_28->setText("^");
    if(sow[3][1]==0) ui->pushButton_28->setText(" ");
    if(sow[3][2]==1){
        if(table[3][2]==0) ui->pushButton_22->setText("-");
        if(table[3][2]==1) ui->pushButton_22->setText("1");
        if(table[3][2]==2) ui->pushButton_22->setText("2");
        if(table[3][2]==3) ui->pushButton_22->setText("3");
        if(table[3][2]==4) ui->pushButton_22->setText("4");
        if(table[3][2]==5) ui->pushButton_22->setText("5");
        if(table[3][2]==6) ui->pushButton_22->setText("6");
        if(table[3][2]==7) ui->pushButton_22->setText("7");
        if(table[3][2]==8) ui->pushButton_22->setText("8");
        if(table[3][2]==9) ui->pushButton_22->setText("*");
}
    if(sow[3][2]==2) ui->pushButton_22->setText("^");
    if(sow[3][2]==0) ui->pushButton_22->setText(" ");
    if(sow[3][3]==1){
        if(table[3][3]==0) ui->pushButton_26->setText("-");
        if(table[3][3]==1) ui->pushButton_26->setText("1");
        if(table[3][3]==2) ui->pushButton_26->setText("2");
        if(table[3][3]==3) ui->pushButton_26->setText("3");
        if(table[3][3]==4) ui->pushButton_26->setText("4");
        if(table[3][3]==5) ui->pushButton_26->setText("5");
        if(table[3][3]==6) ui->pushButton_26->setText("6");
        if(table[3][3]==7) ui->pushButton_26->setText("7");
        if(table[3][3]==8) ui->pushButton_26->setText("8");
        if(table[3][3]==9) ui->pushButton_26->setText("*");
}
    if(sow[3][3]==2) ui->pushButton_26->setText("^");
    if(sow[3][3]==0) ui->pushButton_26->setText(" ");
    if(sow[3][4]==1){
        if(table[3][4]==0) ui->pushButton_21->setText("-");
        if(table[3][4]==1) ui->pushButton_21->setText("1");
        if(table[3][4]==2) ui->pushButton_21->setText("2");
        if(table[3][4]==3) ui->pushButton_21->setText("3");
        if(table[3][4]==4) ui->pushButton_21->setText("4");
        if(table[3][4]==5) ui->pushButton_21->setText("5");
        if(table[3][4]==6) ui->pushButton_21->setText("6");
        if(table[3][4]==7) ui->pushButton_21->setText("7");
        if(table[3][4]==8) ui->pushButton_21->setText("8");
        if(table[3][4]==9) ui->pushButton_21->setText("*");
}
    if(sow[3][4]==2) ui->pushButton_21->setText("^");
    if(sow[3][4]==0) ui->pushButton_21->setText(" ");
    if(sow[3][5]==1){
        if(table[3][5]==0) ui->pushButton_29->setText("-");
        if(table[3][5]==1) ui->pushButton_29->setText("1");
        if(table[3][5]==2) ui->pushButton_29->setText("2");
        if(table[3][5]==3) ui->pushButton_29->setText("3");
        if(table[3][5]==4) ui->pushButton_29->setText("4");
        if(table[3][5]==5) ui->pushButton_29->setText("5");
        if(table[3][5]==6) ui->pushButton_29->setText("6");
        if(table[3][5]==7) ui->pushButton_29->setText("7");
        if(table[3][5]==8) ui->pushButton_29->setText("8");
        if(table[3][5]==9) ui->pushButton_29->setText("*");
}
    if(sow[3][5]==2) ui->pushButton_29->setText("^");
    if(sow[3][5]==0) ui->pushButton_29->setText(" ");
    if(sow[3][6]==1){
        if(table[3][6]==0) ui->pushButton_24->setText("-");
        if(table[3][6]==1) ui->pushButton_24->setText("1");
        if(table[3][6]==2) ui->pushButton_24->setText("2");
        if(table[3][6]==3) ui->pushButton_24->setText("3");
        if(table[3][6]==4) ui->pushButton_24->setText("4");
        if(table[3][6]==5) ui->pushButton_24->setText("5");
        if(table[3][6]==6) ui->pushButton_24->setText("6");
        if(table[3][6]==7) ui->pushButton_24->setText("7");
        if(table[3][6]==8) ui->pushButton_24->setText("8");
        if(table[3][6]==9) ui->pushButton_24->setText("*");
}
    if(sow[3][6]==2) ui->pushButton_24->setText("^");
    if(sow[3][6]==0) ui->pushButton_24->setText(" ");
    if(sow[3][7]==1){
        if(table[3][7]==0) ui->pushButton_31->setText("-");
        if(table[3][7]==1) ui->pushButton_31->setText("1");
        if(table[3][7]==2) ui->pushButton_31->setText("2");
        if(table[3][7]==3) ui->pushButton_31->setText("3");
        if(table[3][7]==4) ui->pushButton_31->setText("4");
        if(table[3][7]==5) ui->pushButton_31->setText("5");
        if(table[3][7]==6) ui->pushButton_31->setText("6");
        if(table[3][7]==7) ui->pushButton_31->setText("7");
        if(table[3][7]==8) ui->pushButton_31->setText("8");
        if(table[3][7]==9) ui->pushButton_31->setText("*");
}
    if(sow[3][7]==2) ui->pushButton_31->setText("^");
    if(sow[3][7]==0) ui->pushButton_31->setText(" ");
    if(sow[4][0]==1){
        if(table[4][0]==0) ui->pushButton_58->setText("-");
        if(table[4][0]==1) ui->pushButton_58->setText("1");
        if(table[4][0]==2) ui->pushButton_58->setText("2");
        if(table[4][0]==3) ui->pushButton_58->setText("3");
        if(table[4][0]==4) ui->pushButton_58->setText("4");
        if(table[4][0]==5) ui->pushButton_58->setText("5");
        if(table[4][0]==6) ui->pushButton_58->setText("6");
        if(table[4][0]==7) ui->pushButton_58->setText("7");
        if(table[4][0]==8) ui->pushButton_58->setText("8");
        if(table[4][0]==9) ui->pushButton_58->setText("*");
}
    if(sow[4][0]==2) ui->pushButton_58->setText("^");
    if(sow[4][0]==0) ui->pushButton_58->setText(" ");
    if(sow[4][1]==1){
        if(table[4][1]==0) ui->pushButton_41->setText("-");
        if(table[4][1]==1) ui->pushButton_41->setText("1");
        if(table[4][1]==2) ui->pushButton_41->setText("2");
        if(table[4][1]==3) ui->pushButton_41->setText("3");
        if(table[4][1]==4) ui->pushButton_41->setText("4");
        if(table[4][1]==5) ui->pushButton_41->setText("5");
        if(table[4][1]==6) ui->pushButton_41->setText("6");
        if(table[4][1]==7) ui->pushButton_41->setText("7");
        if(table[4][1]==8) ui->pushButton_41->setText("8");
        if(table[4][1]==9) ui->pushButton_41->setText("*");
}
    if(sow[4][1]==2) ui->pushButton_41->setText("^");
    if(sow[4][1]==0) ui->pushButton_41->setText(" ");
    if(sow[4][2]==1){
        if(table[4][2]==0) ui->pushButton_37->setText("-");
        if(table[4][2]==1) ui->pushButton_37->setText("1");
        if(table[4][2]==2) ui->pushButton_37->setText("2");
        if(table[4][2]==3) ui->pushButton_37->setText("3");
        if(table[4][2]==4) ui->pushButton_37->setText("4");
        if(table[4][2]==5) ui->pushButton_37->setText("5");
        if(table[4][2]==6) ui->pushButton_37->setText("6");
        if(table[4][2]==7) ui->pushButton_37->setText("7");
        if(table[4][2]==8) ui->pushButton_37->setText("8");
        if(table[4][2]==9) ui->pushButton_37->setText("*");
}
    if(sow[4][2]==2) ui->pushButton_37->setText("^");
    if(sow[4][2]==0) ui->pushButton_37->setText(" ");
    if(sow[4][3]==1){
        if(table[4][3]==0) ui->pushButton_38->setText("-");
        if(table[4][3]==1) ui->pushButton_38->setText("1");
        if(table[4][3]==2) ui->pushButton_38->setText("2");
        if(table[4][3]==3) ui->pushButton_38->setText("3");
        if(table[4][3]==4) ui->pushButton_38->setText("4");
        if(table[4][3]==5) ui->pushButton_38->setText("5");
        if(table[4][3]==6) ui->pushButton_38->setText("6");
        if(table[4][3]==7) ui->pushButton_38->setText("7");
        if(table[4][3]==8) ui->pushButton_38->setText("8");
        if(table[4][3]==9) ui->pushButton_38->setText("*");
}
    if(sow[4][3]==2) ui->pushButton_38->setText("^");
    if(sow[4][3]==0) ui->pushButton_38->setText(" ");
    if(sow[4][4]==1){
        if(table[4][4]==0) ui->pushButton_33->setText("-");
        if(table[4][4]==1) ui->pushButton_33->setText("1");
        if(table[4][4]==2) ui->pushButton_33->setText("2");
        if(table[4][4]==3) ui->pushButton_33->setText("3");
        if(table[4][4]==4) ui->pushButton_33->setText("4");
        if(table[4][4]==5) ui->pushButton_33->setText("5");
        if(table[4][4]==6) ui->pushButton_33->setText("6");
        if(table[4][4]==7) ui->pushButton_33->setText("7");
        if(table[4][4]==8) ui->pushButton_33->setText("8");
        if(table[4][4]==9) ui->pushButton_33->setText("*");
}
    if(sow[4][4]==2) ui->pushButton_33->setText("^");
    if(sow[4][4]==0) ui->pushButton_33->setText(" ");
    if(sow[4][5]==1){
        if(table[4][5]==0) ui->pushButton_51->setText("-");
        if(table[4][5]==1) ui->pushButton_51->setText("1");
        if(table[4][5]==2) ui->pushButton_51->setText("2");
        if(table[4][5]==3) ui->pushButton_51->setText("3");
        if(table[4][5]==4) ui->pushButton_51->setText("4");
        if(table[4][5]==5) ui->pushButton_51->setText("5");
        if(table[4][5]==6) ui->pushButton_51->setText("6");
        if(table[4][5]==7) ui->pushButton_51->setText("7");
        if(table[4][5]==8) ui->pushButton_51->setText("8");
        if(table[4][5]==9) ui->pushButton_51->setText("*");
}
    if(sow[4][5]==2) ui->pushButton_51->setText("^");
    if(sow[4][5]==0) ui->pushButton_51->setText(" ");
    if(sow[4][6]==1){
        if(table[4][6]==0) ui->pushButton_61->setText("-");
        if(table[4][6]==1) ui->pushButton_61->setText("1");
        if(table[4][6]==2) ui->pushButton_61->setText("2");
        if(table[4][6]==3) ui->pushButton_61->setText("3");
        if(table[4][6]==4) ui->pushButton_61->setText("4");
        if(table[4][6]==5) ui->pushButton_61->setText("5");
        if(table[4][6]==6) ui->pushButton_61->setText("6");
        if(table[4][6]==7) ui->pushButton_61->setText("7");
        if(table[4][6]==8) ui->pushButton_61->setText("8");
        if(table[4][6]==9) ui->pushButton_61->setText("*");
}
    if(sow[4][6]==2) ui->pushButton_61->setText("^");
    if(sow[4][6]==0) ui->pushButton_61->setText(" ");
    if(sow[4][7]==1){
        if(table[4][7]==0) ui->pushButton_64->setText("-");
        if(table[4][7]==1) ui->pushButton_64->setText("1");
        if(table[4][7]==2) ui->pushButton_64->setText("2");
        if(table[4][7]==3) ui->pushButton_64->setText("3");
        if(table[4][7]==4) ui->pushButton_64->setText("4");
        if(table[4][7]==5) ui->pushButton_64->setText("5");
        if(table[4][7]==6) ui->pushButton_64->setText("6");
        if(table[4][7]==7) ui->pushButton_64->setText("7");
        if(table[4][7]==8) ui->pushButton_64->setText("8");
        if(table[4][7]==9) ui->pushButton_64->setText("*");
}
    if(sow[4][7]==2) ui->pushButton_64->setText("^");
    if(sow[4][7]==0) ui->pushButton_64->setText(" ");
    if(sow[5][0]==1){
        if(table[5][0]==0) ui->pushButton_52->setText("-");
        if(table[5][0]==1) ui->pushButton_52->setText("1");
        if(table[5][0]==2) ui->pushButton_52->setText("2");
        if(table[5][0]==3) ui->pushButton_52->setText("3");
        if(table[5][0]==4) ui->pushButton_52->setText("4");
        if(table[5][0]==5) ui->pushButton_52->setText("5");
        if(table[5][0]==6) ui->pushButton_52->setText("6");
        if(table[5][0]==7) ui->pushButton_52->setText("7");
        if(table[5][0]==8) ui->pushButton_52->setText("8");
        if(table[5][0]==9) ui->pushButton_52->setText("*");
}
    if(sow[5][0]==2) ui->pushButton_52->setText("^");
    if(sow[5][0]==0) ui->pushButton_52->setText(" ");
    if(sow[5][1]==1){
        if(table[5][1]==0) ui->pushButton_40->setText("-");
        if(table[5][1]==1) ui->pushButton_40->setText("1");
        if(table[5][1]==2) ui->pushButton_40->setText("2");
        if(table[5][1]==3) ui->pushButton_40->setText("3");
        if(table[5][1]==4) ui->pushButton_40->setText("4");
        if(table[5][1]==5) ui->pushButton_40->setText("5");
        if(table[5][1]==6) ui->pushButton_40->setText("6");
        if(table[5][1]==7) ui->pushButton_40->setText("7");
        if(table[5][1]==8) ui->pushButton_40->setText("8");
        if(table[5][1]==9) ui->pushButton_40->setText("*");
}
    if(sow[5][1]==2) ui->pushButton_40->setText("^");
    if(sow[5][1]==0) ui->pushButton_40->setText(" ");
    if(sow[5][2]==1){
        if(table[5][2]==0) ui->pushButton_53->setText("-");
        if(table[5][2]==1) ui->pushButton_53->setText("1");
        if(table[5][2]==2) ui->pushButton_53->setText("2");
        if(table[5][2]==3) ui->pushButton_53->setText("3");
        if(table[5][2]==4) ui->pushButton_53->setText("4");
        if(table[5][2]==5) ui->pushButton_53->setText("5");
        if(table[5][2]==6) ui->pushButton_53->setText("6");
        if(table[5][2]==7) ui->pushButton_53->setText("7");
        if(table[5][2]==8) ui->pushButton_53->setText("8");
        if(table[5][2]==9) ui->pushButton_53->setText("*");
}
    if(sow[5][2]==2) ui->pushButton_53->setText("^");
    if(sow[5][2]==0) ui->pushButton_53->setText(" ");
    if(sow[5][3]==1){
        if(table[5][3]==0) ui->pushButton_45->setText("-");
        if(table[5][3]==1) ui->pushButton_45->setText("1");
        if(table[5][3]==2) ui->pushButton_45->setText("2");
        if(table[5][3]==3) ui->pushButton_45->setText("3");
        if(table[5][3]==4) ui->pushButton_45->setText("4");
        if(table[5][3]==5) ui->pushButton_45->setText("5");
        if(table[5][3]==6) ui->pushButton_45->setText("6");
        if(table[5][3]==7) ui->pushButton_45->setText("7");
        if(table[5][3]==8) ui->pushButton_45->setText("8");
        if(table[5][3]==9) ui->pushButton_45->setText("*");
}
    if(sow[5][3]==2) ui->pushButton_45->setText("^");
    if(sow[5][3]==0) ui->pushButton_45->setText(" ");
    if(sow[5][4]==1){
        if(table[5][4]==0) ui->pushButton_39->setText("-");
        if(table[5][4]==1) ui->pushButton_39->setText("1");
        if(table[5][4]==2) ui->pushButton_39->setText("2");
        if(table[5][4]==3) ui->pushButton_39->setText("3");
        if(table[5][4]==4) ui->pushButton_39->setText("4");
        if(table[5][4]==5) ui->pushButton_39->setText("5");
        if(table[5][4]==6) ui->pushButton_39->setText("6");
        if(table[5][4]==7) ui->pushButton_39->setText("7");
        if(table[5][4]==8) ui->pushButton_39->setText("8");
        if(table[5][4]==9) ui->pushButton_39->setText("*");
}
    if(sow[5][4]==2) ui->pushButton_39->setText("^");
    if(sow[5][4]==0) ui->pushButton_39->setText(" ");
    if(sow[5][5]==1){
        if(table[5][5]==0) ui->pushButton_56->setText("-");
        if(table[5][5]==1) ui->pushButton_56->setText("1");
        if(table[5][5]==2) ui->pushButton_56->setText("2");
        if(table[5][5]==3) ui->pushButton_56->setText("3");
        if(table[5][5]==4) ui->pushButton_56->setText("4");
        if(table[5][5]==5) ui->pushButton_56->setText("5");
        if(table[5][5]==6) ui->pushButton_56->setText("6");
        if(table[5][5]==7) ui->pushButton_56->setText("7");
        if(table[5][5]==8) ui->pushButton_56->setText("8");
        if(table[5][5]==9) ui->pushButton_56->setText("*");
}
    if(sow[5][5]==2) ui->pushButton_56->setText("^");
    if(sow[5][5]==0) ui->pushButton_56->setText(" ");
    if(sow[5][6]==1){
        if(table[5][6]==0) ui->pushButton_59->setText("-");
        if(table[5][6]==1) ui->pushButton_59->setText("1");
        if(table[5][6]==2) ui->pushButton_59->setText("2");
        if(table[5][6]==3) ui->pushButton_59->setText("3");
        if(table[5][6]==4) ui->pushButton_59->setText("4");
        if(table[5][6]==5) ui->pushButton_59->setText("5");
        if(table[5][6]==6) ui->pushButton_59->setText("6");
        if(table[5][6]==7) ui->pushButton_59->setText("7");
        if(table[5][6]==8) ui->pushButton_59->setText("8");
        if(table[5][6]==9) ui->pushButton_59->setText("*");
}
    if(sow[5][6]==2) ui->pushButton_59->setText("^");
    if(sow[5][6]==0) ui->pushButton_59->setText(" ");
    if(sow[5][7]==1){
        if(table[5][7]==0) ui->pushButton_42->setText("-");
        if(table[5][7]==1) ui->pushButton_42->setText("1");
        if(table[5][7]==2) ui->pushButton_42->setText("2");
        if(table[5][7]==3) ui->pushButton_42->setText("3");
        if(table[5][7]==4) ui->pushButton_42->setText("4");
        if(table[5][7]==5) ui->pushButton_42->setText("5");
        if(table[5][7]==6) ui->pushButton_42->setText("6");
        if(table[5][7]==7) ui->pushButton_42->setText("7");
        if(table[5][7]==8) ui->pushButton_42->setText("8");
        if(table[5][7]==9) ui->pushButton_42->setText("*");
}
    if(sow[5][7]==2) ui->pushButton_42->setText("^");
    if(sow[5][7]==0) ui->pushButton_42->setText(" ");
    if(sow[6][0]==1){
        if(table[6][0]==0) ui->pushButton_48->setText("-");
        if(table[6][0]==1) ui->pushButton_48->setText("1");
        if(table[6][0]==2) ui->pushButton_48->setText("2");
        if(table[6][0]==3) ui->pushButton_48->setText("3");
        if(table[6][0]==4) ui->pushButton_48->setText("4");
        if(table[6][0]==5) ui->pushButton_48->setText("5");
        if(table[6][0]==6) ui->pushButton_48->setText("6");
        if(table[6][0]==7) ui->pushButton_48->setText("7");
        if(table[6][0]==8) ui->pushButton_48->setText("8");
        if(table[6][0]==9) ui->pushButton_48->setText("*");
}
    if(sow[6][0]==2) ui->pushButton_48->setText("^");
    if(sow[6][0]==0) ui->pushButton_48->setText(" ");
    if(sow[6][1]==1){
        if(table[6][1]==0) ui->pushButton_50->setText("-");
        if(table[6][1]==1) ui->pushButton_50->setText("1");
        if(table[6][1]==2) ui->pushButton_50->setText("2");
        if(table[6][1]==3) ui->pushButton_50->setText("3");
        if(table[6][1]==4) ui->pushButton_50->setText("4");
        if(table[6][1]==5) ui->pushButton_50->setText("5");
        if(table[6][1]==6) ui->pushButton_50->setText("6");
        if(table[6][1]==7) ui->pushButton_50->setText("7");
        if(table[6][1]==8) ui->pushButton_50->setText("8");
        if(table[6][1]==9) ui->pushButton_50->setText("*");
}
    if(sow[6][1]==2) ui->pushButton_50->setText("^");
    if(sow[6][1]==0) ui->pushButton_50->setText(" ");
    if(sow[6][2]==1){
        if(table[6][2]==0) ui->pushButton_57->setText("-");
        if(table[6][2]==1) ui->pushButton_57->setText("1");
        if(table[6][2]==2) ui->pushButton_57->setText("2");
        if(table[6][2]==3) ui->pushButton_57->setText("3");
        if(table[6][2]==4) ui->pushButton_57->setText("4");
        if(table[6][2]==5) ui->pushButton_57->setText("5");
        if(table[6][2]==6) ui->pushButton_57->setText("6");
        if(table[6][2]==7) ui->pushButton_57->setText("7");
        if(table[6][2]==8) ui->pushButton_57->setText("8");
        if(table[6][2]==9) ui->pushButton_57->setText("*");
}
    if(sow[6][2]==2) ui->pushButton_57->setText("^");
    if(sow[6][2]==0) ui->pushButton_57->setText(" ");
    if(sow[6][3]==1){
        if(table[6][3]==0) ui->pushButton_55->setText("-");
        if(table[6][3]==1) ui->pushButton_55->setText("1");
        if(table[6][3]==2) ui->pushButton_55->setText("2");
        if(table[6][3]==3) ui->pushButton_55->setText("3");
        if(table[6][3]==4) ui->pushButton_55->setText("4");
        if(table[6][3]==5) ui->pushButton_55->setText("5");
        if(table[6][3]==6) ui->pushButton_55->setText("6");
        if(table[6][3]==7) ui->pushButton_55->setText("7");
        if(table[6][3]==8) ui->pushButton_55->setText("8");
        if(table[6][3]==9) ui->pushButton_55->setText("*");
}
    if(sow[6][3]==2) ui->pushButton_55->setText("^");
    if(sow[6][3]==0) ui->pushButton_55->setText(" ");
    if(sow[6][4]==1){
        if(table[6][4]==0) ui->pushButton_47->setText("-");
        if(table[6][4]==1) ui->pushButton_47->setText("1");
        if(table[6][4]==2) ui->pushButton_47->setText("2");
        if(table[6][4]==3) ui->pushButton_47->setText("3");
        if(table[6][4]==4) ui->pushButton_47->setText("4");
        if(table[6][4]==5) ui->pushButton_47->setText("5");
        if(table[6][4]==6) ui->pushButton_47->setText("6");
        if(table[6][4]==7) ui->pushButton_47->setText("7");
        if(table[6][4]==8) ui->pushButton_47->setText("8");
        if(table[6][4]==9) ui->pushButton_47->setText("*");
}
    if(sow[6][4]==2) ui->pushButton_47->setText("^");
    if(sow[6][4]==0) ui->pushButton_47->setText(" ");
    if(sow[6][5]==1){
        if(table[6][5]==0) ui->pushButton_34->setText("-");
        if(table[6][5]==1) ui->pushButton_34->setText("1");
        if(table[6][5]==2) ui->pushButton_34->setText("2");
        if(table[6][5]==3) ui->pushButton_34->setText("3");
        if(table[6][5]==4) ui->pushButton_34->setText("4");
        if(table[6][5]==5) ui->pushButton_34->setText("5");
        if(table[6][5]==6) ui->pushButton_34->setText("6");
        if(table[6][5]==7) ui->pushButton_34->setText("7");
        if(table[6][5]==8) ui->pushButton_34->setText("8");
        if(table[6][5]==9) ui->pushButton_34->setText("*");
}
    if(sow[6][5]==2) ui->pushButton_34->setText("^");
    if(sow[6][5]==0) ui->pushButton_34->setText(" ");
    if(sow[6][6]==1){
        if(table[6][6]==0) ui->pushButton_46->setText("-");
        if(table[6][6]==1) ui->pushButton_46->setText("1");
        if(table[6][6]==2) ui->pushButton_46->setText("2");
        if(table[6][6]==3) ui->pushButton_46->setText("3");
        if(table[6][6]==4) ui->pushButton_46->setText("4");
        if(table[6][6]==5) ui->pushButton_46->setText("5");
        if(table[6][6]==6) ui->pushButton_46->setText("6");
        if(table[6][6]==7) ui->pushButton_46->setText("7");
        if(table[6][6]==8) ui->pushButton_46->setText("8");
        if(table[6][6]==9) ui->pushButton_46->setText("*");
}
    if(sow[6][6]==2) ui->pushButton_46->setText("^");
    if(sow[6][6]==0) ui->pushButton_46->setText(" ");
    if(sow[6][7]==1){
        if(table[6][7]==0) ui->pushButton_44->setText("-");
        if(table[6][7]==1) ui->pushButton_44->setText("1");
        if(table[6][7]==2) ui->pushButton_44->setText("2");
        if(table[6][7]==3) ui->pushButton_44->setText("3");
        if(table[6][7]==4) ui->pushButton_44->setText("4");
        if(table[6][7]==5) ui->pushButton_44->setText("5");
        if(table[6][7]==6) ui->pushButton_44->setText("6");
        if(table[6][7]==7) ui->pushButton_44->setText("7");
        if(table[6][7]==8) ui->pushButton_44->setText("8");
        if(table[6][7]==9) ui->pushButton_44->setText("*");
}
    if(sow[6][7]==2) ui->pushButton_44->setText("^");
    if(sow[6][7]==0) ui->pushButton_44->setText(" ");
    if(sow[7][0]==1){
        if(table[7][0]==0) ui->pushButton_54->setText("-");
        if(table[7][0]==1) ui->pushButton_54->setText("1");
        if(table[7][0]==2) ui->pushButton_54->setText("2");
        if(table[7][0]==3) ui->pushButton_54->setText("3");
        if(table[7][0]==4) ui->pushButton_54->setText("4");
        if(table[7][0]==5) ui->pushButton_54->setText("5");
        if(table[7][0]==6) ui->pushButton_54->setText("6");
        if(table[7][0]==7) ui->pushButton_54->setText("7");
        if(table[7][0]==8) ui->pushButton_54->setText("8");
        if(table[7][0]==9) ui->pushButton_54->setText("*");
}
    if(sow[7][0]==2) ui->pushButton_54->setText("^");
    if(sow[7][0]==0) ui->pushButton_54->setText(" ");
    if(sow[7][1]==1){
        if(table[7][1]==0) ui->pushButton_49->setText("-");
        if(table[7][1]==1) ui->pushButton_49->setText("1");
        if(table[7][1]==2) ui->pushButton_49->setText("2");
        if(table[7][1]==3) ui->pushButton_49->setText("3");
        if(table[7][1]==4) ui->pushButton_49->setText("4");
        if(table[7][1]==5) ui->pushButton_49->setText("5");
        if(table[7][1]==6) ui->pushButton_49->setText("6");
        if(table[7][1]==7) ui->pushButton_49->setText("7");
        if(table[7][1]==8) ui->pushButton_49->setText("8");
        if(table[7][1]==9) ui->pushButton_49->setText("*");
}
    if(sow[7][1]==2) ui->pushButton_49->setText("^");
    if(sow[7][1]==0) ui->pushButton_49->setText(" ");
    if(sow[7][2]==1){
        if(table[7][2]==0) ui->pushButton_43->setText("-");
        if(table[7][2]==1) ui->pushButton_43->setText("1");
        if(table[7][2]==2) ui->pushButton_43->setText("2");
        if(table[7][2]==3) ui->pushButton_43->setText("3");
        if(table[7][2]==4) ui->pushButton_43->setText("4");
        if(table[7][2]==5) ui->pushButton_43->setText("5");
        if(table[7][2]==6) ui->pushButton_43->setText("6");
        if(table[7][2]==7) ui->pushButton_43->setText("7");
        if(table[7][2]==8) ui->pushButton_43->setText("8");
        if(table[7][2]==9) ui->pushButton_43->setText("*");
}
    if(sow[7][2]==2) ui->pushButton_43->setText("^");
    if(sow[7][2]==0) ui->pushButton_43->setText(" ");
    if(sow[7][3]==1){
        if(table[7][3]==0) ui->pushButton_60->setText("-");
        if(table[7][3]==1) ui->pushButton_60->setText("1");
        if(table[7][3]==2) ui->pushButton_60->setText("2");
        if(table[7][3]==3) ui->pushButton_60->setText("3");
        if(table[7][3]==4) ui->pushButton_60->setText("4");
        if(table[7][3]==5) ui->pushButton_60->setText("5");
        if(table[7][3]==6) ui->pushButton_60->setText("6");
        if(table[7][3]==7) ui->pushButton_60->setText("7");
        if(table[7][3]==8) ui->pushButton_60->setText("8");
        if(table[7][3]==9) ui->pushButton_60->setText("*");
}
    if(sow[7][3]==2) ui->pushButton_60->setText("^");
    if(sow[7][3]==0) ui->pushButton_60->setText(" ");
    if(sow[7][4]==1){
        if(table[7][4]==0) ui->pushButton_36->setText("-");
        if(table[7][4]==1) ui->pushButton_36->setText("1");
        if(table[7][4]==2) ui->pushButton_36->setText("2");
        if(table[7][4]==3) ui->pushButton_36->setText("3");
        if(table[7][4]==4) ui->pushButton_36->setText("4");
        if(table[7][4]==5) ui->pushButton_36->setText("5");
        if(table[7][4]==6) ui->pushButton_36->setText("6");
        if(table[7][4]==7) ui->pushButton_36->setText("7");
        if(table[7][4]==8) ui->pushButton_36->setText("8");
        if(table[7][4]==9) ui->pushButton_36->setText("*");
}
    if(sow[7][4]==2) ui->pushButton_36->setText("^");
    if(sow[7][4]==0) ui->pushButton_36->setText(" ");
    if(sow[7][5]==1){
        if(table[7][5]==0) ui->pushButton_63->setText("-");
        if(table[7][5]==1) ui->pushButton_63->setText("1");
        if(table[7][5]==2) ui->pushButton_63->setText("2");
        if(table[7][5]==3) ui->pushButton_63->setText("3");
        if(table[7][5]==4) ui->pushButton_63->setText("4");
        if(table[7][5]==5) ui->pushButton_63->setText("5");
        if(table[7][5]==6) ui->pushButton_63->setText("6");
        if(table[7][5]==7) ui->pushButton_63->setText("7");
        if(table[7][5]==8) ui->pushButton_63->setText("8");
        if(table[7][5]==9) ui->pushButton_63->setText("*");
}
    if(sow[7][5]==2) ui->pushButton_63->setText("^");
    if(sow[7][5]==0) ui->pushButton_63->setText(" ");
    if(sow[7][6]==1){
        if(table[7][6]==0) ui->pushButton_62->setText("-");
        if(table[7][6]==1) ui->pushButton_62->setText("1");
        if(table[7][6]==2) ui->pushButton_62->setText("2");
        if(table[7][6]==3) ui->pushButton_62->setText("3");
        if(table[7][6]==4) ui->pushButton_62->setText("4");
        if(table[7][6]==5) ui->pushButton_62->setText("5");
        if(table[7][6]==6) ui->pushButton_62->setText("6");
        if(table[7][6]==7) ui->pushButton_62->setText("7");
        if(table[7][6]==8) ui->pushButton_62->setText("8");
        if(table[7][6]==9) ui->pushButton_62->setText("*");
}
    if(sow[7][6]==2) ui->pushButton_62->setText("^");
    if(sow[7][6]==0) ui->pushButton_62->setText(" ");
    if(sow[7][7]==1){
        if(table[7][7]==0) ui->pushButton_35->setText("-");
        if(table[7][7]==1) ui->pushButton_35->setText("1");
        if(table[7][7]==2) ui->pushButton_35->setText("2");
        if(table[7][7]==3) ui->pushButton_35->setText("3");
        if(table[7][7]==4) ui->pushButton_35->setText("4");
        if(table[7][7]==5) ui->pushButton_35->setText("5");
        if(table[7][7]==6) ui->pushButton_35->setText("6");
        if(table[7][7]==7) ui->pushButton_35->setText("7");
        if(table[7][7]==8) ui->pushButton_35->setText("8");
        if(table[7][7]==9) ui->pushButton_35->setText("*");
}
    if(sow[7][7]==2) ui->pushButton_35->setText("^");
    if(sow[7][7]==0) ui->pushButton_35->setText(" ");
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    i1 = 0; j1 = 0;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
    win();
    bazi();
}
void MainWindow::on_pushButton_2_clicked()
{
    i1 = 0; j1 = 1;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
       lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_3_clicked()
{
    i1 = 0; j1 = 2;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_4_clicked()
{
    i1 = 0; j1 = 3;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_5_clicked()
{
    i1 = 0; j1 = 4;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_6_clicked()
{
    i1 = 0; j1 = 5;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_7_clicked()
{
    i1 = 0; j1 = 6;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_8_clicked()
{
    i1 = 0; j1 = 7;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_13_clicked()
{
    i1 = 1; j1 = 0;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_15_clicked()
{
    i1 = 1; j1 = 1;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_9_clicked()
{
    i1 = 1; j1 = 2;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_11_clicked()
{
    i1 = 1; j1 = 3;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_12_clicked()
{
    i1 = 1; j1 = 4;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_16_clicked()
{
    i1 = 1; j1 = 5;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_10_clicked()
{
    i1 = 1; j1 = 6;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_14_clicked()
{
    i1 = 1; j1 = 7;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_23_clicked()
{
    i1 = 2; j1 = 0;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_30_clicked()
{
    i1 = 2; j1 = 1;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_17_clicked()
{
    i1 = 2; j1 = 2;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_19_clicked()
{
    i1 = 2; j1 = 3;
    if(sow[i1][j1]==1){
        QMessageBox msgBox;
        msgBox.setText("opened before! try again! :D");
        msgBox.exec();
   }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_20_clicked()
{
    i1 = 2; j1 = 4;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_32_clicked()
{
    i1 = 2; j1 = 5;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_18_clicked()
{
    i1 = 2; j1 = 6;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_25_clicked()
{
    i1 = 2; j1 = 7;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_27_clicked()
{
    i1 = 3; j1 = 0;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_28_clicked()
{
    i1 = 3; j1 = 1;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_22_clicked()
{
    i1 = 3; j1 = 2;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_26_clicked()
{
    i1 = 3; j1 = 3;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_21_clicked()
{
    i1 = 3; j1 = 4;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_29_clicked()
{
    i1 = 3; j1 = 5;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_24_clicked()
{
    i1 = 3; j1 = 6;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_31_clicked()
{
    i1 = 3; j1 = 7;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_58_clicked()
{
    i1 = 4; j1 = 0;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_41_clicked()
{
    i1 = 4; j1 = 1;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_37_clicked()
{
    i1 = 4; j1 = 2;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_38_clicked()
{
    i1 = 4; j1 = 3;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_33_clicked()
{
    i1 = 4; j1 = 4;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_51_clicked()
{
    i1 = 4; j1 = 5;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_61_clicked()
{
    i1 = 4; j1 = 6;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_64_clicked()
{
    i1 = 4; j1 = 7;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}

void MainWindow::on_pushButton_52_clicked()
{
    i1 = 5; j1 = 0;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_40_clicked()
{
    i1 = 5; j1 = 1;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_53_clicked()
{
    i1 = 5; j1 = 2;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_45_clicked()
{
    i1 = 5; j1 = 3;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_39_clicked()
{
    i1 = 5; j1 = 4;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_56_clicked()
{
    i1 = 5; j1 = 5;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_59_clicked()
{
    i1 = 5; j1 = 6;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_42_clicked()
{
    i1 = 5; j1 = 7;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_48_clicked()
{
    i1 = 6; j1 = 0;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_50_clicked()
{
     i1 = 6; j1 = 1;
     if(sow[i1][j1]==1){
          QMessageBox msgBox;
          msgBox.setText("opened before! try again! :D");
          msgBox.exec();
     }
     if(sow[i1][j1]==0) open(i1,j1);
     if(sow[i1][j1]==2) sow[i1][j1]=0;
     if(table[i1][j1]==9){
         lost();
     }
     win();
     bazi();
}
void MainWindow::on_pushButton_57_clicked()
{
     i1 = 6; j1 = 2;
     if(sow[i1][j1]==1){
          QMessageBox msgBox;
          msgBox.setText("opened before! try again! :D");
          msgBox.exec();
     }
     if(sow[i1][j1]==0) open(i1,j1);
     if(sow[i1][j1]==2) sow[i1][j1]=0;
     if(table[i1][j1]==9){
         lost();
     }
      win();
     bazi();
}
void MainWindow::on_pushButton_55_clicked()
{
     i1 = 6; j1 = 3;
     if(sow[i1][j1]==1){
          QMessageBox msgBox;
          msgBox.setText("opened before! try again! :D");
          msgBox.exec();
     }
     if(sow[i1][j1]==0) open(i1,j1);
     if(sow[i1][j1]==2) sow[i1][j1]=0;
     if(table[i1][j1]==9){
         lost();
     }
      win();
     bazi();
}
void MainWindow::on_pushButton_47_clicked()
{
     i1 = 6; j1 = 4;
     if(sow[i1][j1]==1){
          QMessageBox msgBox;
          msgBox.setText("opened before! try again! :D");
          msgBox.exec();
     }
     if(sow[i1][j1]==0) open(i1,j1);
     if(sow[i1][j1]==2) sow[i1][j1]=0;
     if(table[i1][j1]==9){
         lost();
     }
      win();
     bazi();
}
void MainWindow::on_pushButton_34_clicked()
{
     i1 = 6; j1 = 5;
     if(sow[i1][j1]==1){
          QMessageBox msgBox;
          msgBox.setText("opened before! try again! :D");
          msgBox.exec();
     }
     if(sow[i1][j1]==0) open(i1,j1);
     if(sow[i1][j1]==2) sow[i1][j1]=0;
     if(table[i1][j1]==9){
         lost();
     }
      win();
     bazi();
}
void MainWindow::on_pushButton_46_clicked()
{
     i1 = 6; j1 = 6;
     if(sow[i1][j1]==1){
          QMessageBox msgBox;
          msgBox.setText("opened before! try again! :D");
          msgBox.exec();
     }
     if(sow[i1][j1]==0) open(i1,j1);
     if(sow[i1][j1]==2) sow[i1][j1]=0;
     if(table[i1][j1]==9){
         lost();
     }
      win();
     bazi();
}
void MainWindow::on_pushButton_44_clicked()
{
     i1 = 6; j1 = 7;
     if(sow[i1][j1]==1){
          QMessageBox msgBox;
          msgBox.setText("opened before! try again! :D");
          msgBox.exec();
     }
     if(sow[i1][j1]==0) open(i1,j1);
     if(sow[i1][j1]==2) sow[i1][j1]=0;
     if(table[i1][j1]==9){
         lost();
     }
      win();
     bazi();
}
void MainWindow::on_pushButton_54_clicked()
{
     i1 = 7; j1 = 0;
     if(sow[i1][j1]==1){
          QMessageBox msgBox;
          msgBox.setText("opened before! try again! :D");
          msgBox.exec();
     }
     if(sow[i1][j1]==0) open(i1,j1);
     if(sow[i1][j1]==2) sow[i1][j1]=0;
     if(table[i1][j1]==9){
         lost();
     }
      win();
     bazi();
}
void MainWindow::on_pushButton_49_clicked()
{
    i1 = 7; j1 = 1;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_43_clicked()
{
    i1 = 7; j1 = 2;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_60_clicked()
{
    i1 = 7; j1 = 3;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_36_clicked()
{
    i1 = 7; j1 = 4;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_63_clicked()
{
    i1 = 7; j1 = 5;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_62_clicked()
{
    i1 = 7; j1 = 6;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}
void MainWindow::on_pushButton_35_clicked()
{
    i1 = 7; j1 = 7;
    if(sow[i1][j1]==1){
         QMessageBox msgBox;
         msgBox.setText("Opened before! try again! :D");
         msgBox.exec();
    }
    if(sow[i1][j1]==0) open(i1,j1);
    if(sow[i1][j1]==2) sow[i1][j1]=0;
    if(table[i1][j1]==9){
        lost();
    }
     win();
    bazi();
}

#include "Snake.h"
#include<windows.h>
#include<mmsystem.h>
#include<conio.h>
#pragma comment(lib,"winmm.lib");

Snake  player;
Snake enemy[2];//(AI_1 nearest food)

Food food[FOODS];
IMAGE HELP_I,BACKGROUND,BK_README,HEAD[4],HEAD_CURRENT,BODY[5],FOOD[5],GAME_OVER;
IMAGE ENEMY_1,ENEMY_2;
IMAGE WIN,LOSE;


int count_food=0;
int frame=60;
float fps=1000/frame;
clock_t start,end;

int count=0;
time_t g_time=60;

void timer(){
    if(end-start<=fps)
        Sleep(fps-(end-start));
        count++;
        if(count==frame&&g_time!=0){
            g_time--;
            count=0;
        }
}


void loadsource(){
    loadimage(&BACKGROUND,_T("./img/bk.png"),W_WIDTH,W_HEIGHT,true);
    loadimage(&BK_README,_T("./img/bk_readme.png"),140,180,true);
    loadimage(&GAME_OVER,_T("./img/gameover.png"),GAMEOVER_WIDTH,GAMEOVER_HEIGHT,true);

    loadimage(&ENEMY_1,_T("./img/enemy_1.png"),ENEMYSIZE,ENEMYSIZE,true);
    loadimage(&ENEMY_2,_T("./img/enemy_2.png"),ENEMYSIZE,ENEMYSIZE,true);

    loadimage(&BODY[0],_T("./img/blue.png"),PLAYERSIZE,PLAYERSIZE,true);
    loadimage(&BODY[1],_T("./img/green.png"),PLAYERSIZE,PLAYERSIZE,true);
    loadimage(&BODY[2],_T("./img/red.png"),PLAYERSIZE,PLAYERSIZE,true);
    loadimage(&BODY[3],_T("./img/pink.png"),PLAYERSIZE,PLAYERSIZE,true);
    loadimage(&BODY[4],_T("./img/purple.png"),PLAYERSIZE,PLAYERSIZE,true);

    loadimage(&HEAD[0],_T("./img/up_t.png"),PLAYERSIZE,PLAYERSIZE,true);
    loadimage(&HEAD[1],_T("./img/down_t.png"),PLAYERSIZE,PLAYERSIZE,true);
    loadimage(&HEAD[2],_T("./img/left_t.png"),PLAYERSIZE,PLAYERSIZE,true);
    loadimage(&HEAD[3],_T("./img/right_t.png"),PLAYERSIZE,PLAYERSIZE,true);
    loadimage(&HEAD_CURRENT,_T("./img/right_t.png"),PLAYERSIZE,PLAYERSIZE,true);

    loadimage(&FOOD[0],_T("./img/food_blue.png"),FOODSIZE,FOODSIZE,true);
    loadimage(&FOOD[1],_T("./img/food_green.png"),FOODSIZE,FOODSIZE,true);
    loadimage(&FOOD[2],_T("./img/food_red.png"),FOODSIZE,FOODSIZE,true);
    loadimage(&FOOD[3],_T("./img/food_pink.png"),FOODSIZE,FOODSIZE,true);
    loadimage(&FOOD[4],_T("./img/food_purple.png"),FOODSIZE,FOODSIZE,true);

    loadimage(&HELP_I,_T("./img/help.png"),GAMEOVER_WIDTH+120,GAMEOVER_HEIGHT+120,true);
    loadimage(&WIN,_T("./img/win.png"),GAMEOVER_WIDTH+120,GAMEOVER_HEIGHT+120,true);
    loadimage(&LOSE,_T("./img/lose.png"),GAMEOVER_WIDTH+120,GAMEOVER_HEIGHT+120,true);
}

void Move(){
    if(GetAsyncKeyState('W'))
    {
        player.GetState()=UP;
        HEAD_CURRENT=HEAD[0];
    }
    else if(GetAsyncKeyState('S'))
    {
        player.GetState()=DOWN;
        HEAD_CURRENT=HEAD[1];
    }
    else if(GetAsyncKeyState('A'))
    {
        player.GetState()=LEFT;
        HEAD_CURRENT=HEAD[2];
    }
    else if (GetAsyncKeyState('D'))
    {
        player.GetState()=RIGHT;
        HEAD_CURRENT=HEAD[3];
    }
}

void InitFood(){
    for(int i=0;i<FOODS;i++){
        food[i].RandInit(food);
    }
}

void InputFood(){
    for(int i=0;i<FOODS;i++){
        if(food[i].GetIsDie()==false)
        putimage(food[i].GetX(),food[i].GetY(),&FOOD[food[i].GetColor()]);
    }
}

void InputInformation(){
    TCHAR score[6],time[4];
    int LengthtoScore=player.GetLength()/4;
    int LengthtoScore_0=enemy[0].GetLength()/4;
    int LengthtoScore_1=enemy[1].GetLength()/4;

    outtextxy(10,W_HEIGHT-40,_T("'Q'   帮助"));
    outtextxy(10,W_HEIGHT-20,_T("'Esc' 退出"));

    //整数转换为自适应字符串宏命令 
    _itot_s(g_time,time,10);
    outtextxy(W_WIDTH/2-50,40,_T("时间: "));
    outtextxy(W_WIDTH/2-10,40,time);
    outtextxy(W_WIDTH/2+20,40,_T("秒"));

    _itot_s(LengthtoScore,score,10);
    outtextxy(10,10,_T("小娥宝宝: "));
    outtextxy(80,10,score);

    _itot_s(LengthtoScore_0,score,10);
    outtextxy(10,30,_T("IKUN: "));
    outtextxy(60,30,score);

    _itot_s(LengthtoScore_1,score,10);
    outtextxy(10,50,_T("DORO: "));
    outtextxy(60,50,score);
}

void Input(){ //图层覆盖，越靠后的图像图层越高，输出的优先级也就越高
    Body* hp=player.GetBody().GetNext();
    Body* hp_1=enemy[0].GetBody().GetNext();
    Body* hp_2=enemy[1].GetBody().GetNext();
    putimage(0,0,&BACKGROUND);
    //putimage(0,0,&BK_README);
    InputFood();

    
    while(hp_2!=NULL)
    {
        putimage(hp_2->GetBx(),hp_2->GetBy(),&BODY[2]);
        hp_2=hp_2->GetNext();
    }
    
    while(hp_1!=NULL)
    {
        putimage(hp_1->GetBx(),hp_1->GetBy(),&BODY[1]);
        hp_1=hp_1->GetNext();
    }

    while(hp!=NULL)
    {
        putimage(hp->GetBx(),hp->GetBy(),&BODY[hp->GetColor()]);
        hp=hp->GetNext();
    }

    settextcolor(WHITE);
    putimage(enemy[1].GetHead().GetHx(),enemy[1].GetHead().GetHy(),&ENEMY_2);
    outtextxy(enemy[1].GetHead().GetHx(),enemy[1].GetHead().GetHy()-18,_T("DORO"));

    putimage(enemy[0].GetHead().GetHx(),enemy[0].GetHead().GetHy(),&ENEMY_1);
    outtextxy(enemy[0].GetHead().GetHx(),enemy[0].GetHead().GetHy()-18,_T("IKUN"));

    putimage(player.GetHead().GetHx(),player.GetHead().GetHy(),&HEAD_CURRENT);
    outtextxy(player.GetHead().GetHx()-10,player.GetHead().GetHy()-18,_T("小娥宝宝"));
    settextcolor(RED);

    InputInformation();
}

void CheckGameState(){
    int x=player.GetHead().GetHx();
    int y=player.GetHead().GetHy();
    //用PLAYERSPEED增加容错性，提高检测范围
    if(x<PLAYERSPEED||(x+PLAYERSIZE)<PLAYERSPEED||(x+PLAYERSIZE)>W_WIDTH-PLAYERSPEED||y<0||(y+PLAYERSIZE)>W_HEIGHT-PLAYERSPEED)
        player.GetIsDie()=true;
    
    player.CheckCollision_P(enemy,2);

    if(player.GetIsDie()==true)
    {
        mciSendString(_T("stop ./media/bk_music.mp3"),NULL,0,NULL);
        putimage(W_WIDTH/2-GAMEOVER_WIDTH/2,W_HEIGHT/2-GAMEOVER_HEIGHT/2,&GAME_OVER);
    }
}

void CheckFoodState(Snake &s){
    for(int i=0;i<FOODS;i++){
        if(food[i].GetIsDie()==false&&food[i].Check(s.GetHead().GetHx(),s.GetHead().GetHy()))
        {
            food[i].GetIsDie()=true;
            for(int j=0;j<4;j++)
                s.AddBody(food[i].GetColor());
            count_food++;
        }
        
        if(count_food>=FOODS/4)
        {
            count_food=0;
            for(int i=0;i<FOODS;i++){
                if(food[i].GetIsDie()==true)
                    food[i].RandInit(food);
            }
        }
    }
}

bool PROGRAM=true;

void HELP(){
    if(GetAsyncKeyState('Q')){
        while(1){
            putimage(W_WIDTH/2-GAMEOVER_WIDTH/2-100,W_HEIGHT/2-GAMEOVER_HEIGHT/2-100,&HELP_I);
            FlushBatchDraw();
            if(GetAsyncKeyState('R'))
                break;
            if(GetAsyncKeyState(27))
            {
                PROGRAM=false;
                break;
            }
        }
    }
}

void GAME(){
    while(player.GetIsDie()==false){
        BeginBatchDraw();

        start=clock();

        if(GetAsyncKeyState(27))  //27 -> Esc
        {
            PROGRAM=false;
            break;
        }

        cleardevice();

        Move();
        player.UpdateBody();
        player.UpdatePHead();
        CheckFoodState(player);     //chek food state and snake state

        enemy[0].UpdateBody();
        enemy[0].enemy_move_nf(food);     //lookford to nearest food
        CheckFoodState(enemy[0]);
        
        enemy[1].UpdateBody();
        enemy[1].enemy_move_nf(food);     //lookford to nearest food
        CheckFoodState(enemy[1]);

        Input();

        CheckGameState();

        if(g_time==0)
        {
        player.GetIsDie()=true;
        PROGRAM=false;
        while(1){
            if(player.GetLength()>=enemy[0].GetLength()&&player.GetLength()>=enemy[1].GetLength())
                putimage(W_WIDTH/2-GAMEOVER_WIDTH/2-100,W_HEIGHT/2-GAMEOVER_HEIGHT/2-100,&WIN);
            else
                putimage(W_WIDTH/2-GAMEOVER_WIDTH/2-100,W_HEIGHT/2-GAMEOVER_HEIGHT/2-100,&LOSE);

            FlushBatchDraw();

            if(GetAsyncKeyState(27))
                break;
        }
        }

        FlushBatchDraw();
        
        end=clock();
        timer();
        HELP();

        EndBatchDraw();
    }
    
    if(GetAsyncKeyState(27))  //27 -> Esc
        PROGRAM=false;
}

int main(){
    srand((unsigned int)time(NULL));
    InitFood(); 
    enemy[0].enemy_rand_initxy();
    enemy[1].enemy_rand_initxy();

    loadsource();

    initgraph(W_WIDTH,W_HEIGHT,1);

    mciSendString(_T("open ./media/bk_music.mp3"),NULL,0,NULL);
    mciSendString(_T("play ./media/bk_music.mp3 repeat"),NULL,0,NULL);
    
    setbkmode(TRANSPARENT);       //设置文本样式为背景透明,该函数后面的文本均设置为该样式
                                  //修改窗口中文本的样式，因此依赖于图形库窗口，须在窗口启动之后再调用
                                  //和BeginBatchDraw和EndBatchDraw的范围用法一样
                                  //setbkcolor,set.... 
    settextcolor(RED);                     
    //       
    while(PROGRAM){

        GAME();
    }
    //
    closegraph();
    return 0;
}
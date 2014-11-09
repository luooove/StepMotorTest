/************************************************************

 Copyright (C), 2014 SWJTUMakerspace

 FileName: Stepmotor test

 Author: Xiaoxiang Luo
 Version :0.1V
 Date: 2014年11月9日

 Description: // 用来控制两个电机的测试程序


***********************************************************/

//端口定义
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

//************变量定义******************
int StepDelayTime=100;  
int StepCount = 0;

//************初始化******************
void setup()
{
  Serial.begin(9600);
  pinMode(X_STEP_PIN  , OUTPUT);
  pinMode(X_DIR_PIN    , OUTPUT);
  pinMode(X_ENABLE_PIN    , OUTPUT);
  
  pinMode(Y_STEP_PIN  , OUTPUT);
  pinMode(Y_DIR_PIN    , OUTPUT);
  pinMode(Y_ENABLE_PIN    , OUTPUT);
  
  digitalWrite(X_ENABLE_PIN    , LOW);
  digitalWrite(Y_ENABLE_PIN    , LOW);
  
}



void loop()
{
   
  StepControlOne(0,0,1,0);
}

void Forward_X()
{
  digitalWrite(X_DIR_PIN    , HIGH);
  digitalWrite(X_STEP_PIN    , HIGH);
  delayMicroseconds(StepDelayTime);  
  digitalWrite(X_STEP_PIN    , LOW);
  delayMicroseconds(StepDelayTime);  
}
void Forward_Y()
{
  digitalWrite(Y_DIR_PIN    , HIGH);
  digitalWrite(Y_STEP_PIN    , HIGH);
  delayMicroseconds(StepDelayTime);  
  digitalWrite(Y_STEP_PIN    , LOW);
  delayMicroseconds(StepDelayTime);  
}
void Backward_X()
{
  digitalWrite(X_DIR_PIN    , LOW);
  digitalWrite(X_STEP_PIN    , HIGH);
  delayMicroseconds(StepDelayTime);  
  digitalWrite(X_STEP_PIN    , LOW);
  delayMicroseconds(StepDelayTime);  
}
void Backward_Y()
{
  digitalWrite(Y_DIR_PIN    , LOW);
  digitalWrite(Y_STEP_PIN    , HIGH);
  delayMicroseconds(StepDelayTime);  
  digitalWrite(Y_STEP_PIN    , LOW);
  delayMicroseconds(StepDelayTime);  
}



//**************控制X Y电机一步的函数****************
//Dir_X：控制X电机的方向 1为正转，0为反向转
//Dir_Y：控制Y电机的方向 1为正转，0为反向转
//Step_X：控制X电机是否走一步 如果为1电机走一步，如果0电机不动
//Step_Y：控制Y电机是否走一步 如果为1电机走一步，如果0电机不动
void StepControlOne(boolean Dir_X,boolean Dir_Y,boolean Step_X,boolean Step_Y) //if Dir_X
{
  
  digitalWrite(X_DIR_PIN    , Dir_X);
  digitalWrite(Y_DIR_PIN    , Dir_Y);
  if(Step_X)
    {
      digitalWrite(X_STEP_PIN    , HIGH);
      delayMicroseconds(StepDelayTime);  
      digitalWrite(X_STEP_PIN    , LOW);
      delayMicroseconds(StepDelayTime);  
    }
  else
    {
      delayMicroseconds(StepDelayTime);  
      delayMicroseconds(StepDelayTime);  
    }
  if(Step_Y)
    {
      digitalWrite(Y_STEP_PIN    , HIGH);
      delayMicroseconds(StepDelayTime);  
      digitalWrite(Y_STEP_PIN    , LOW);
      delayMicroseconds(StepDelayTime);  
    }
  else
    {
      delayMicroseconds(StepDelayTime);  
      delayMicroseconds(StepDelayTime);  
    }
  //Serial.println(Step_X);
}


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>  // 用于Sleep函数和清屏

// 1. 定义Dog类
typedef struct {
    char name[20];
    int energy;
    int happiness;  // 新增：心情值
    bool isHungry;
    bool isSleepy;  // 新增：是否困了
    int barkCount;  // 新增：叫的次数统计
    
    void (*bark)(struct Dog*);
    void (*eat)(struct Dog*, int foodAmount);
    void (*sleep)(struct Dog*);     // 新增：睡觉方法
    void (*play)(struct Dog*);      // 新增：玩耍方法
    void (*showStatus)(struct Dog*); // 新增：显示状态
} Dog;

// 2. 辅助函数：显示分隔线
void showDivider() {
    printf("\n══════════════════════════════════════════\n");
}

// 3. 辅助函数：显示标题
void showTitle(const char* title) {
    printf("\n┌──────────────────────────────────────┐\n");
    printf("│ %-36s │\n", title);
    printf("└──────────────────────────────────────┘\n");
}

// 4. 实现各种方法
void dogBark(Dog* self) {
    if(self->energy <= 0) {
        printf("💤 %s：Zzz...（睡得太沉了，叫不醒）\n", self->name);
        return;
    }
    
    if(self->energy > 0) {
        // 不同心情有不同的叫声
        if(self->happiness > 70) {
            printf("🐕 %s：汪汪汪！(๑>ᴗ<๑) 好开心！\n", self->name);
        } else if(self->happiness > 30) {
            printf("🐕 %s：汪汪！(・∀・)\n", self->name);
        } else {
            printf("🐕 %s：呜...汪... (╥﹏╥) 有点难过\n", self->name);
        }
        
        self->energy -= 3 + rand() % 3;  // 消耗3-5点能量
        self->happiness += 2;            // 叫一下会开心一点
        self->barkCount++;
        
        if(self->energy < 8) {
            self->isHungry = true;
        }
        if(self->energy < 5) {
            self->isSleepy = true;
        }
    }
}

void dogEat(Dog* self, int foodAmount) {
    if(foodAmount <= 0) {
        printf("❓ %s：？？？（疑惑地看着空气）\n", self->name);
        return;
    }
    
    // 根据食物量有不同的反应
    if(foodAmount < 5) {
        printf("🍪 %s：吧唧吧唧... (´･ω･`) 这么点不够吃呀\n", self->name);
        self->happiness -= 5;
    } else if(foodAmount < 15) {
        printf("🍗 %s：啊呜啊呜！(๑´ڡ`๑) 好吃！\n", self->name);
        self->happiness += 10;
    } else {
        printf("🍖 %s：嗝～(￣▽￣*) 吃得好撑！\n", self->name);
        self->happiness += 5;
        self->isSleepy = true;  // 吃撑了会困
    }
    
    self->energy += foodAmount * 2;
    self->isHungry = false;
    
    // 能量不能超过上限
    if(self->energy > 30) self->energy = 30;
}

void dogSleep(Dog* self) {
    if(self->energy >= 25) {
        printf("😴 %s：我还不想睡！( •̀ ω •́ )✧\n", self->name);
        return;
    }
    
    int sleepTime = 10 + rand() % 10;  // 睡10-19点能量
    printf("💤 %s：Zzz... 睡得好香...\n", self->name);
    printf("    （恢复了 %d 点能量）\n", sleepTime);
    
    self->energy += sleepTime;
    if(self->energy > 30) self->energy = 30;
    self->happiness += 8;
    self->isSleepy = false;
    
    // 睡太久会饿
    if(rand() % 2 == 0) {
        self->isHungry = true;
        printf("    （睡醒后有点饿了）\n");
    }
}

void dogPlay(Dog* self) {
    if(self->energy < 10) {
        printf("😫 %s：太累了，玩不动了... (；´д｀)ゞ\n", self->name);
        return;
    }
    
    printf("🎾 %s：追球球！接飞盘！(≧∇≦)ﾉ 太好玩了！\n", self->name);
    
    self->energy -= 8;
    self->happiness += 15;
    
    // 玩得太疯可能会饿
    if(rand() % 3 == 0) {
        self->isHungry = true;
        printf("    （玩饿了）\n");
    }
}

void dogShowStatus(Dog* self) {
    printf("\n📊 %s 的状态：\n", self->name);
    printf("   ❤️  能量：");
    for(int i = 0; i < 10; i++) {
        if(i < self->energy / 3) printf("█");
        else printf("░");
    }
    printf(" %d/30\n", self->energy);
    
    printf("   😊  心情：");
    for(int i = 0; i < 10; i++) {
        if(i < self->happiness / 10) printf("█");
        else printf("░");
    }
    printf(" %d/100\n", self->happiness);
    
    printf("   📈  今日叫了 %d 次\n", self->barkCount);
    
    printf("   🚩  状态：");
    if(self->isHungry) printf(" 🍽️饥饿 ");
    if(self->isSleepy) printf(" 😴困倦 ");
    if(!self->isHungry && !self->isSleepy) printf(" ✅良好");
    printf("\n");
}

// 5. 构造函数
Dog createDog(const char* name) {
    Dog d;
    strcpy(d.name, name);
    d.energy = 20 + rand() % 11;  // 初始能量20-30
    d.happiness = 60 + rand() % 31; // 初始心情60-90
    d.isHungry = false;
    d.isSleepy = (rand() % 4 == 0); // 25%几率初始困倦
    d.barkCount = 0;
    
    d.bark = dogBark;
    d.eat = dogEat;
    d.sleep = dogSleep;
    d.play = dogPlay;
    d.showStatus = dogShowStatus;
    
    return d;
}

// 6. 新增：时间流逝系统
void timePasses(Dog* dog1, Dog* dog2, int hours) {
    printf("\n⏰ 时间过去了 %d 小时...\n", hours);
    
    dog1->energy -= hours * 2;
    dog2->energy -= hours * 2;
    dog1->happiness -= hours * 3;
    dog2->happiness -= hours * 3;
    
    // 防止值过低
    if(dog1->energy < 0) dog1->energy = 0;
    if(dog2->energy < 0) dog2->energy = 0;
    if(dog1->happiness < 0) dog1->happiness = 0;
    if(dog2->happiness < 0) dog2->happiness = 0;
    
    // 能量低时会饿
    if(dog1->energy < 10) dog1->isHungry = true;
    if(dog2->energy < 10) dog2->isHungry = true;
    
    // 心情特别低时会困
    if(dog1->happiness < 20) dog1->isSleepy = true;
    if(dog2->happiness < 20) dog2->isSleepy = true;
}

// 7. 新增：随机事件系统
void randomEvent(Dog* dog) {
    int event = rand() % 6;
    
    switch(event) {
        case 0:
            printf("\n🎉 %s 发现了一只蝴蝶，追着玩了好一会儿！\n", dog->name);
            dog->happiness += 10;
            dog->energy -= 5;
            break;
        case 1:
            printf("\n🌧️  下雨了，%s 有点郁闷...\n", dog->name);
            dog->happiness -= 8;
            break;
        case 2:
            printf("\n☀️  阳光很好，%s 在晒太阳，心情变好了！\n", dog->name);
            dog->happiness += 12;
            break;
        case 3:
            printf("\n🐱 %s 看到了一只猫，兴奋地叫了起来！\n", dog->name);
            dog->bark(dog);
            break;
        case 4:
            printf("\n🍖 %s 闻到了邻居家烤肉的味道，更饿了...\n", dog->name);
            dog->isHungry = true;
            break;
        case 5:
            printf("\n💤 %s 打了个大大的哈欠...\n", dog->name);
            dog->isSleepy = true;
            break;
    }
}

// 8. 主程序 - 模拟养狗体验
int main(void) {
    srand(time(NULL));  // 初始化随机种子
    system("chcp 65001 > nul");  // 设置控制台为UTF-8编码（Windows）
    system("cls");
    
    showTitle("🐕 欢迎来到虚拟养狗模拟器！ 🐕");
    printf("\n请给你的两只狗狗起名：\n");
    
    char name1[20], name2[20];
    printf("第一只狗狗的名字：");
    scanf("%s", name1);
    printf("第二只狗狗的名字：");
    scanf("%s", name2);
    
    // 创建狗狗
    Dog dog1 = createDog(name1);
    Dog dog2 = createDog(name2);
    
    system("cls");
    showTitle("🏡 你的狗狗家庭 🏡");
    printf("\n你领养了两只可爱的狗狗：\n");
    printf("1. %s - 精力充沛的小可爱\n", dog1.name);
    printf("2. %s - 活泼好动的小调皮\n", dog2.name);
    
    Sleep(2000);
    
    int day = 1;
    bool running = true;
    
    while(running) {
        system("cls");
        showTitle(day == 1 ? "🏠 第一天 - 与狗狗相处 🏠" : 
                 day == 2 ? "🌞 第二天 - 美好时光 🌞" :
                 "🌈 日常养狗生活 🌈");
        
        // 显示两只狗狗的状态
        dog1.showStatus(&dog1);
        dog2.showStatus(&dog2);
        
        showDivider();
        
        // 主菜单
        printf("\n你可以：\n");
        printf("1. 和 %s 互动\n", dog1.name);
        printf("2. 和 %s 互动\n", dog2.name);
        printf("3. 同时和两只狗狗互动\n");
        printf("4. 让时间流逝（休息一下）\n");
        printf("5. 查看帮助\n");
        printf("0. 结束今天（退出游戏）\n");
        printf("\n请选择（1-5，0退出）：");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 0:  // 退出
                running = false;
                showTitle("感谢你照顾狗狗！");
                printf("\n%s 和 %s 会想念你的！\n", dog1.name, dog2.name);
                printf("今日统计：\n");
                printf("- %s 总共叫了 %d 次\n", dog1.name, dog1.barkCount);
                printf("- %s 总共叫了 %d 次\n", dog2.name, dog2.barkCount);
                printf("\n游戏结束，再见！👋\n");
                break;
                
            case 1:  // 与第一只狗互动
                system("cls");
                showTitle("与狗狗互动");
                printf("\n你想对 %s 做什么？\n", dog1.name);
                printf("1. 让它叫一声\n");
                printf("2. 喂食\n");
                printf("3. 让它睡觉\n");
                printf("4. 和它玩耍\n");
                printf("5. 查看状态\n");
                printf("0. 返回\n");
                
                int action1;
                scanf("%d", &action1);
                
                switch(action1) {
                    case 1: dog1.bark(&dog1); break;
                    case 2: 
                        printf("喂多少狗粮？（建议5-15）：");
                        int food;
                        scanf("%d", &food);
                        dog1.eat(&dog1, food);
                        break;
                    case 3: dog1.sleep(&dog1); break;
                    case 4: dog1.play(&dog1); break;
                    case 5: dog1.showStatus(&dog1); break;
                }
                
                // 随机事件
                if(rand() % 3 == 0 && action1 != 0 && action1 != 5) {
                    randomEvent(&dog1);
                }
                
                printf("\n按回车继续...");
                getchar(); getchar();
                break;
                
            case 2:  // 与第二只狗互动
                system("cls");
                showTitle("与狗狗互动");
                printf("\n你想对 %s 做什么？\n", dog2.name);
                printf("1. 让它叫一声\n");
                printf("2. 喂食\n");
                printf("3. 让它睡觉\n");
                printf("4. 和它玩耍\n");
                printf("5. 查看状态\n");
                printf("0. 返回\n");
                
                int action2;
                scanf("%d", &action2);
                
                switch(action2) {
                    case 1: dog2.bark(&dog2); break;
                    case 2: 
                        printf("喂多少狗粮？（建议5-15）：");
                        int food;
                        scanf("%d", &food);
                        dog2.eat(&dog2, food);
                        break;
                    case 3: dog2.sleep(&dog2); break;
                    case 4: dog2.play(&dog2); break;
                    case 5: dog2.showStatus(&dog2); break;
                }
                
                // 随机事件
                if(rand() % 3 == 0 && action2 != 0 && action2 != 5) {
                    randomEvent(&dog2);
                }
                
                printf("\n按回车继续...");
                getchar(); getchar();
                break;
                
            case 3:  // 同时与两只狗互动
                system("cls");
                showTitle("集体活动时间！");
                printf("\n你想做什么集体活动？\n");
                printf("1. 让两只狗狗一起叫\n");
                printf("2. 举办吃饭比赛\n");
                printf("3. 一起玩耍\n");
                printf("4. 一起散步（时间流逝）\n");
                
                int groupAction;
                scanf("%d", &groupAction);
                
                switch(groupAction) {
                    case 1:
                        printf("\n狗狗二重唱开始！\n");
                        dog1.bark(&dog1);
                        dog2.bark(&dog2);
                        printf("🎵 两只狗狗叫得好欢快！\n");
                        break;
                    case 2:
                        printf("\n🏆 吃饭比赛开始！\n");
                        int food1 = 8 + rand() % 8;
                        int food2 = 8 + rand() % 8;
                        dog1.eat(&dog1, food1);
                        dog2.eat(&dog2, food2);
                        printf("\n比赛结果：\n");
                        printf("%s 吃了 %d 份，%s 吃了 %d 份\n", 
                               dog1.name, food1, dog2.name, food2);
                        break;
                    case 3:
                        printf("\n🎪 游乐时间到！\n");
                        dog1.play(&dog1);
                        dog2.play(&dog2);
                        printf("\n狗狗们玩得好开心！\n");
                        break;
                    case 4:
                        printf("\n🌳 带着狗狗们去散步...\n");
                        timePasses(&dog1, &dog2, 2);
                        printf("散步回来，狗狗们消耗了些能量，但很开心！\n");
                        break;
                }
                
                printf("\n按回车继续...");
                getchar(); getchar();
                break;
                
            case 4:  // 时间流逝
                printf("\n让时间流逝多久？（小时，建议1-6）：");
                int hours;
                scanf("%d", &hours);
                timePasses(&dog1, &dog2, hours);
                
                // 每天结束后进入下一天
                static int hoursPassed = 0;
                hoursPassed += hours;
                if(hoursPassed >= 24) {
                    hoursPassed = 0;
                    day++;
                    printf("\n🌙 一天结束了，新的一天开始了！\n");
                }
                
                printf("\n按回车继续...");
                getchar(); getchar();
                break;
                
            case 5:  // 帮助
                system("cls");
                showTitle("养狗指南");
                printf("\n📖 如何照顾好你的狗狗：\n");
                printf("1. 能量（❤️）：狗狗活动需要能量，能量过低会饿\n");
                printf("2. 心情（😊）：保持狗狗好心情，它们会更活泼\n");
                printf("3. 饥饿（🍽️）：及时喂食，否则狗狗会不开心\n");
                printf("4. 困倦（😴）：让狗狗睡觉可以恢复能量\n");
                printf("\n💡 小贴士：\n");
                printf("- 喂食建议5-15份狗粮\n");
                printf("- 玩耍会快速提升心情但消耗能量\n");
                printf("- 注意平衡各项数值\n");
                printf("\n按回车返回...");
                getchar(); getchar();
                break;
                
            default:
                printf("无效的选择！\n");
                Sleep(1000);
        }
        
        // 检查狗狗状态，给出提示
        if(dog1.isHungry || dog2.isHungry) {
            printf("\n⚠️  提示：有狗狗饿了，记得喂食哦！\n");
            Sleep(1500);
        }
        if(dog1.energy < 5 || dog2.energy < 5) {
            printf("\n⚠️  提示：有狗狗太累了，让它休息一下吧！\n");
            Sleep(1500);
        }
    }
    
    return 0;
}
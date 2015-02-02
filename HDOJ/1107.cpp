////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-05-15 13:55:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1107
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int sta[15][15]; //每格的人数
struct Node{
	int neili, wuyi, hp, attack; //内力、武艺、和生命力、攻击力
	char danwei;
	int x, y, dir;
} dizi[1002];
int sumS, sumW, sumE; //少林、武当、峨眉弟子剩余人数
int hpS, hpW, hpE;
int t, steps, id;
char ch[2];


int calAttack(Node temp){
	if(temp.danwei == 'S'){
		temp.attack = (0.5 * temp.neili + 0.5 * temp.wuyi) * (temp.hp + 10) / 100;				
	}else if(temp.danwei == 'W'){
		temp.attack = (0.8 * temp.neili + 0.2 * temp.wuyi) * (temp.hp + 10) / 100;
	}else{
		temp.attack = (0.2 * temp.neili + 0.8 * temp.wuyi) * (temp.hp + 10) / 100;
	}
	return temp.attack;
}

bool check(Node tt){
	if(tt.x < 1 || tt.x > 12) return 0;
	if(tt.y < 1 || tt.y > 12) return 0;
	return 1;
}

void move(){
	for(int i = 0; i < id; ++i){
		if(dizi[i].hp){ //alive
			if(dizi[i].danwei == 'S'){
				--sta[dizi[i].x][dizi[i].y];
				dizi[i].x += dizi[i].dir;
				if(!check(dizi[i])) 
					dizi[i].dir *= -1, dizi[i].x += 2 * dizi[i].dir;
				++sta[dizi[i].x][dizi[i].y];
			}else if(dizi[i].danwei == 'W'){
				--sta[dizi[i].x][dizi[i].y];
				dizi[i].y += dizi[i].dir;
				if(!check(dizi[i])) 
					dizi[i].dir *= -1, dizi[i].y += 2 * dizi[i].dir;
				++sta[dizi[i].x][dizi[i].y];
			}else{
				if(dizi[i].x == 1 && dizi[i].y == 12 || 
					dizi[i].x == 12 && dizi[i].y == 1) continue;
				--sta[dizi[i].x][dizi[i].y];
				dizi[i].x += dizi[i].dir; dizi[i].y += dizi[i].dir;
				if(!check(dizi[i])){
					dizi[i].dir *= -1;
					dizi[i].y += 2 * dizi[i].dir;
					dizi[i].x += 2 * dizi[i].dir;
				}
				++sta[dizi[i].x][dizi[i].y];
			}
		}
	}
}

int find(int i, int j, int k){
	while(k < id){
		if(dizi[k].x == i && dizi[k].y == j && dizi[k].hp) return k;
		++k;
	}
	return -1;
}

void battle(){
	int t1, t2;
	for(int i = 1; i <= 12; ++i){
		for(int j = 1; j <= 12; ++j){
			if(sta[i][j] == 2){
				t1 = find(i, j, 0);
				t2 = find(i, j, t1 + 1);
				if(dizi[t1].danwei != dizi[t2].danwei){
					dizi[t1].attack = calAttack(dizi[t1]);
					dizi[t2].attack = calAttack(dizi[t2]);
					dizi[t1].hp -= dizi[t2].attack;
					dizi[t2].hp -= dizi[t1].attack;
					if(dizi[t1].hp <= 0) dizi[t1].hp = 0, --sta[i][j];
					if(dizi[t2].hp <= 0) dizi[t2].hp = 0, --sta[i][j];
				}
			}
		}
	}
}

int main(){	
	scanf("%d", &t);
	Node temp;
	while(t--){
		memset(sta, 0, sizeof(sta));
		id = sumS = sumW = sumE = 0;
		hpS = hpW = hpE = 0;
		scanf("%d", &steps);
		while(scanf("%s", ch), ch[0] != '0'){
			scanf("%d%d%d%d%d", &temp.x, &temp.y, &temp.neili, &temp.wuyi, &temp.hp);
			temp.danwei = ch[0];
			temp.dir = 1; //正方向
			++sta[temp.x][temp.y];
			dizi[id++] = temp;
		}
		while(steps--){
			battle();
			move();
		}
		for(int i = 0; i < id; ++i)
			if(dizi[i].hp){
				if(dizi[i].danwei == 'S'){
					++sumS;
					hpS += dizi[i].hp;
				}else if(dizi[i].danwei == 'W'){
					++sumW;
					hpW += dizi[i].hp;
				}else{
					++sumE;
					hpE += dizi[i].hp;
				}
			}
		printf("%d %d\n", sumS, hpS);
		printf("%d %d\n", sumW, hpW);
		printf("%d %d\n***\n", sumE, hpE);
	}
	return 0;
}
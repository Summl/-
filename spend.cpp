#include"spend.h"

//1.¼��ѧ��������Ϣ
void addStudentSpend(){
	printf("----------1.¼��ѧ��������Ϣ----------\n");
	//�������ݵ�����
	//�·�����
	maxIndex ++;
	Spends[maxIndex].month = createMonth();
	if(Spends[maxIndex].month>12){
		printf("----------��һ��----------\n");
	}
	Spends[maxIndex].month=Spends[maxIndex].month % 12 ;

	//��ѧ��������Ϣ��Ϣ��ֵ
	printf("�����뼾�ڣ�");	
	while(1){
		scanf("%s",Spends[maxIndex].season);
		if((strcmp(Spends[maxIndex].season,"����")!=0) && 
			(strcmp(Spends[maxIndex].season,"�ļ�")!=0) && 
			(strcmp(Spends[maxIndex].season,"�＾")!=0) && 
			(strcmp(Spends[maxIndex].season,"����")!=0)){
				printf("����������������룺\n");
				continue;
		}else if(Spends[maxIndex].month == 12 ||Spends[maxIndex].month == 1 ||Spends[maxIndex].month == 2 ){
			if((strcmp(Spends[maxIndex].season,"����")!=0)){
				printf("����������󣡵�ǰ����Ϊ������\n");
				strcpy(Spends[maxIndex].season,"����");break;
			}else{
				break;
			}			
		}else if(Spends[maxIndex].month == 3 ||Spends[maxIndex].month == 4 ||Spends[maxIndex].month == 5){
			if((strcmp(Spends[maxIndex].season,"����")!=0)){
				printf("����������󣡵�ǰ����Ϊ������\n");
				strcpy(Spends[maxIndex].season,"����");
				break;
			 }else{
				break;
			}
		}else if(Spends[maxIndex].month == 6 ||Spends[maxIndex].month == 7 ||Spends[maxIndex].month == 8){
			if((strcmp(Spends[maxIndex].season,"�ļ�")!=0)){
			printf("����������󣡵�ǰ����Ϊ���ļ�\n");
			strcpy(Spends[maxIndex].season,"�ļ�");
			break;
			}else{
			break;
			}
		}else if(Spends[maxIndex].month == 9 ||Spends[maxIndex].month == 10 ||Spends[maxIndex].month == 11){
			if((strcmp(Spends[maxIndex].season,"�＾")!=0)){
			printf("����������󣡵�ǰ����Ϊ���＾\n");
			strcpy(Spends[maxIndex].season,"�＾");
			break;
			}else{
			break;
			}
		}
	}
	printf("������Է����ѣ�");
	while(1){
		scanf("%d",&Spends[maxIndex].foodSpend);
		if(Spends[maxIndex].foodSpend<0){
			printf("����������������룺\n");
			continue;
		}else{
			break;
		}
	}	
	printf("������绰���ѣ�");
	while(1){
		scanf("%d",&Spends[maxIndex].phoneSpend);
		if(Spends[maxIndex].foodSpend<0){
			printf("����������������룺\n");
			continue;
		}else{
			break;
		}
	}		
	printf("�������������ѣ�");
	while(1){
		scanf("%d",&Spends[maxIndex].bookSpend);
		if(Spends[maxIndex].foodSpend<0){
			printf("����������������룺\n");
			continue;
		}else{
			break;
		}
	}		
	printf("�������������ѣ�");
	while(1){
		scanf("%d",&Spends[maxIndex].otherSpend);
		if(Spends[maxIndex].foodSpend<0){
			printf("����������������룺\n");
			continue;
		}else{
			break;
		}
	}
	printf("�������ڹ���ѧ���룺");
	while(1){
		scanf("%d",&Spends[maxIndex].workStudyIncome);
		if(Spends[maxIndex].foodSpend<0){
			printf("����������������룺\n");
			continue;
		}else{
			break;
		}
	}
	//��������֧��
	Spends[maxIndex].totalSpend =
		Spends[maxIndex].foodSpend +
		Spends[maxIndex].phoneSpend +
		Spends[maxIndex].bookSpend +
		Spends[maxIndex].otherSpend;
	//״̬Ĭ����Ϊ1
	Spends[maxIndex].state = 1;
	//д�ļ�
	if(writeData() == 1){
		printf("���ӳɹ���\n");
	}else{
		printf("����ʧ�ܣ�\n");
	}
}

//2.ɾ��ѧ����������Ϣ��ѧ���ؼ��˻�����²��뱻��¼
//�������ܣ�ɾ��ѧ����Ϣ����ѧ��״̬��Ϊ0
//��������
//����ֵ����
void deleteStudentSpend(){
	printf("----------2.ɾ��ѧ����������Ϣ----------\n");
	int month;
	int index = -1;
	int answer = 0;
	printf("������Ҫɾ�����ѵ��·ݣ�");
	scanf("%d",&month);
	//�����·ݲ���
	index = findIndex(month);
	if(index == -1){
		printf("û�и��·ݵ�������Ϣ��\n");
		return;//��ǰ��������������������ִ�У����ر����ô�
	}
	//����ҵ�����ӡ��ǰѧ��������Ϣ
	printCurrentSpend(index);
	printf("��ȷ��Ҫɾ����1.��  2.��");
	scanf("%d",&answer);
	if(answer == 1){
		//��ǰѧ���Ƿ���У��״̬��Ϊ0
		Spends[index].state = 0;
		//����д�ļ�
		if(writeData() == 1){
			printf("ɾ���ɹ���\n");
		}else{
			printf("ɾ��ʧ�ܣ�\n");
		}
	}
}

//�����·ݲ���
void queryByMonth(){
	int month;
	int index = -1;
	printf("�������·ݣ�");
	scanf("%d",&month);
	index = findIndex(month);
	if(index == -1){
		printf("û�и��µ�������Ϣ��\n");
		return;
	}
	//����ҵ�����ӡѧ����������Ϣ
	printCurrentSpend(index);
}

//�������ܣ����ݼ��ڲ���ѧ��������Ϣ
//��������
//����ֵ����
void queryBySeason(){
	char season[6];
	int index = -1;
	int flag = 0;
	printf("�����뼾�ڣ�");
	scanf("%s",&season);
	//��������
	for(int  i = 0; i <= maxIndex; i++){
		if(Spends[i].state == 1){
			if(strstr(Spends[i].season,season) != NULL){
				flag = 1;
				printCurrentSpend(i);
			}
		}
	}
	if(flag == 0){
		printf("û�иü��ڵ�������Ϣ��\n");
	}
}

//3.����ѧ����������Ϣ
//�������ܣ���ѯѧ����������Ϣ�����Ը����·ݻ򼾽ڲ�ѯ
//��������
//����ֵ����
void searchStudentSpend(){
	printf("----------3.����ѧ����������Ϣ----------\n");
	int select = 0;
	printf("  1.���·ݲ�ѯ  2.�����ڲ�ѯ  \n");
	scanf("%d",&select);
	if(select == 1){
		//���·ݲ���
		queryByMonth();
	}else{
		//�����ڲ���
		queryBySeason();
	}
}

//4.�޸�ѧ����������Ϣ
//�������ܣ��޸�ѧ����������Ϣ���ȸ����·ݲ���
//�ҵ�����������ѧ�����������ݣ�Ȼ����д�ļ�
//��������
//����ֵ����
void updateStudentSpend(){
	printf("----------4.�޸�ѧ����������Ϣ----------\n");
	int month;
	int index = -1;
	printf("������Ҫ�޸ĵ��·ݣ�");
	scanf("%d",&month);
	//�����·ݲ���ѧ����������Ϣ
	index = findIndex(month);
	if(index == -1){
		printf("û�и��·ݵ�������Ϣ��\n");
		return;//��ǰ��������������������ִ�У����ر����ô�
	}
	//����ҵ�����ӡ��ǰѧ����������Ϣ
	printCurrentSpend(index);
	//��������ѧ����������Ϣ
	printf("���������������ļ��ڣ�");
	while(1){
		scanf("%s",Spends[index].season);
		if((strcmp(Spends[index].season,"����")!=0) && 
			(strcmp(Spends[index].season,"�ļ�")!=0) && 
			(strcmp(Spends[index].season,"�＾")!=0) && 
			(strcmp(Spends[index].season,"����")!=0)){
				printf("����������������룺\n");
				continue;
		}else if(Spends[index].month == 12 ||Spends[index].month == 1 ||Spends[index].month == 2 ){
			if((strcmp(Spends[index].season,"����")!=0)){
				printf("����������󣡵�ǰ����Ϊ������\n");
				strcpy(Spends[index].season,"����");break;
			}else{
				break;
			}			
		    }else if(Spends[index].month == 3 ||Spends[index].month == 4 ||Spends[index].month == 5){
			if((strcmp(Spends[index].season,"����")!=0)){
				printf("����������󣡵�ǰ����Ϊ������\n");
				strcpy(Spends[index].season,"����");
				break;
			 }else{
				break;
			}
		    }else if(Spends[index].month == 6 ||Spends[index].month == 7 ||Spends[index].month == 8){
			if((strcmp(Spends[index].season,"�ļ�")!=0)){
			printf("����������󣡵�ǰ����Ϊ���ļ�\n");
			strcpy(Spends[index].season,"�ļ�");
			break;
			}else{
			break;
			}
			}else if(Spends[index].month == 9 ||Spends[index].month == 10 ||Spends[index].month == 11){
			if((strcmp(Spends[index].season,"�＾")!=0)){
			printf("����������󣡵�ǰ����Ϊ���＾\n");
			strcpy(Spends[index].season,"�＾");
			break;
			}else{
			break;
			}
		}
	}
	printf("������Է����ѣ�");
	while(1){
		scanf("%d",&Spends[index].foodSpend);
		if(Spends[index].foodSpend<0){
			printf("����������������룺\n");
			continue;
		}else{
			break;
		}
	}
	printf("������绰���ѣ�");
	while(1){
		scanf("%d",&Spends[index].phoneSpend);
		if(Spends[index].foodSpend<0){
			printf("����������������룺\n");
			continue;
		}else{
			break;
		}
	}		
	printf("�������������ѣ�");
	while(1){
		scanf("%d",&Spends[index].bookSpend);
		if(Spends[index].foodSpend<0){
			printf("����������������룺\n");
			continue;
		}else{
			break;
		}
	}		
	printf("�������������ѣ�");
	while(1){
		scanf("%d",&Spends[index].otherSpend);
		if(Spends[index].foodSpend<0){
			printf("����������������룺\n");
			continue;
		}else{
			break;
		}
	}
	printf("�������ڹ���ѧ���룺");
	while(1){
		scanf("%d",&Spends[index].workStudyIncome);
		if(Spends[index].foodSpend<0){
			printf("����������������룺\n");
			continue;
		}else{
			break;
		}
	}
	//��������֧��
	Spends[index].totalSpend =
		Spends[index].foodSpend +
		Spends[index].phoneSpend +
		Spends[index].foodSpend +
		Spends[index].otherSpend;
	//����д�ļ�
	if(writeData() == 1){
		printf("�޸ĳɹ���\n");
	}else{
		printf("�޸�ʧ�ܣ�\n");
	}
}

//5.��ӡѧ����������Ϣ
//�������ܣ���ӡ������ʵ�ʴ��ڵ�ѧ����������Ϣ
//��������
//����ֵ����
void printfStudentSpend(){
	printf("----------5.��ӡѧ����������Ϣ----------\n");
	printf("|---------------------------------------------------------------------------|\n");
	printf("|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|%-12s|%-8s|\n",
		"�·�","����","�Է�����","�绰����","��������","��������","�ڹ���ѧ����","����֧��");
	printf("|--------+--------+--------+--------+--------+--------+------------+--------|\n");
	for(int i = 0; i<= maxIndex; i++){
		if(Spends[i].state == 1){
			printf("|%-8d|%-8s|%-8d|%-8d|%-8d|%-8d|%-12d|%-8d|\n",
				Spends[i].month,
				Spends[i].season,
				Spends[i].foodSpend,
				Spends[i].phoneSpend,
				Spends[i].bookSpend,
				Spends[i].otherSpend,
				Spends[i].workStudyIncome,
				Spends[i].totalSpend);
			if(i < maxIndex){
				printf("|--------+--------+--------+--------+--------+--------+------------+--------|\n");
			}else{
				printf("|---------------------------------------------------------------------------|\n");
			}
		}
	}
}

//��������ѵ����ֵ
void getMaxSpend()
{
	int maxfoodSpend = Spends[0].foodSpend;
	int maxphoneSpend = Spends[0].phoneSpend;
	int maxbookSpend = Spends[0].bookSpend;
	int maxotherSpend = Spends[0].otherSpend;
	int maxworkStudyIncome = Spends[0].workStudyIncome;
	int i = 0;
	int foodSpendIndex = 0;
	int phoneSpendIndex = 0;
	int bookSpendIndex = 0;
	int otherSpendIndex = 0;
	int workStudyIncomeIndex = 0;

	for(i=1 ;i<=maxIndex; i++){
		if(Spends[i].state ==1)
		{
			if(maxfoodSpend < Spends[i].foodSpend)
			{
				maxfoodSpend = Spends[i].foodSpend;
				foodSpendIndex = i;	
			}
			if(maxphoneSpend < Spends[i].phoneSpend)
			{
				maxphoneSpend = Spends[i].phoneSpend;
				phoneSpendIndex = i;	
			}
			if(maxbookSpend < Spends[i].bookSpend)
			{
				maxbookSpend = Spends[i].bookSpend;
				bookSpendIndex = i;	
			}
			if(maxotherSpend < Spends[i].otherSpend)
			{
				maxotherSpend = Spends[i].otherSpend;
				otherSpendIndex = i;	
			}
			if(maxworkStudyIncome < Spends[i].workStudyIncome)
			{
				maxworkStudyIncome = Spends[i].workStudyIncome;
				workStudyIncomeIndex = i;	
			}

		}

	}
	printf("�Է�������ߣ� %d\n",maxfoodSpend);
	printCurrentSpend(foodSpendIndex);
	printf("�绰������ߣ� %d\n",maxphoneSpend);
	printCurrentSpend(phoneSpendIndex);
	printf("����������ߣ� %d\n",maxbookSpend);
	printCurrentSpend(bookSpendIndex);
	printf("����������ߣ� %d\n",maxotherSpend);
	printCurrentSpend(otherSpendIndex);
	printf("****************************************************************************\n");
	printf("�ڹ���ѧ������ߣ� %d\n",maxworkStudyIncome);
	printCurrentSpend(workStudyIncomeIndex);
}

//��������ѵ�ƽ��ֵ
void getAvgSpend()
{
	double avgfoodSpend = 0;
	double avgphoneSpend = 0;
	double avgbookSpend = 0;
	double avgotherSpend = 0;
	double avgworkStudyIncome=0;
	int i = 0;
	int count = 0; //ʵ���·ݸ��� 
	for(i = 0; i <= maxIndex; i++)
	{
		if(Spends[i].state == 1)
		{
			avgfoodSpend += Spends[i].foodSpend;
			avgphoneSpend += Spends[i].phoneSpend;
			avgbookSpend += Spends[i].bookSpend;
			avgotherSpend += Spends[i].otherSpend;
			avgworkStudyIncome += Spends[i].workStudyIncome;
			count++;
		}
	}
	printf("|-----------------------|\n");
	printf("|%-14s| %-7.2lf|\n","�Է�����ƽ��:",avgfoodSpend/count);
	printf("|--------------+--------|\n");
	printf("|%-14s| %-7.2lf|\n","�绰����ƽ��:",avgphoneSpend/count);
	printf("|--------------+--------|\n");
	printf("|%-14s| %-7.2lf|\n","��������ƽ��",avgbookSpend/count);
	printf("|-----------------------|\n");
	printf("|%-14s| %-7.2lf|\n","��������ƽ��",avgotherSpend/count);
	printf("|-----------------------|\n");
    printf("|*************************|\n");
	printf("|-------------------------|\n");
	printf("|%-14s| %-7.2lf|\n","�ڹ���ѧ����ƽ��",avgworkStudyIncome/count);
	printf("|-------------------------|\n");
} 

//6.ѧ��������Ϣ����
void analysisSyudentSpend(){
	printf("----------6.ͳ��ѧ��������Ϣ----------\n");
	printf("-----ѧ�����ѡ�����ֱ���ߣ�\n");
	getMaxSpend();
	printf("------ѧ�����ѡ�����ֱ�ƽ����\n");
	getAvgSpend();
}


//����ҵ��
//7.���ļ�
//�������ܣ��������ϵ����ݶ�ȡ��������,ֻ�ڳ�������ʱ��һ��
//��������
//����ֵ�����ض�ȡ��������������������ǵ�һ�����У�
//��Ҫ�����ļ�������-1
int readData(){
	//�����ȡ�ļ�������
	int i = 0;
	//7.1.���ļ�
	if((fp = fopen("studentSpendInfo.txt","r")) == NULL){
		//�������ļ�
		fp = fopen("studentSpendInfo.txt","w");
		return -1;
	}
	//7.2.���ļ�
	while (!feof(fp)){
		fscanf(fp,"%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d",
			&Spends[i].month,
			Spends[i].season,
			&Spends[i].foodSpend,
			&Spends[i].phoneSpend,
			&Spends[i].bookSpend,
			&Spends[i].otherSpend,
			&Spends[i].workStudyIncome,
			&Spends[i].totalSpend,
			&Spends[i].state);
		//��ȡһ�����ݣ�����+1
		i++;
	}
	//7.3.�ر��ļ�
	fclose(fp);
	//���ȡһ�У�������0��ʼ
	return i-2;
}

//8.д�ļ�
//�������ܣ��������е�����д�������ϵ��ļ��У�
//��ɾ�Ĳ��������Ҫ����д�ļ�
//��������
//����ֵ��д�ļ��ɹ�����1��ʧ�ܷ���0
int writeData(){
	//��������
	int i = 0;
	//8.1.���ļ�
	if((fp = fopen("studentSpendInfo.txt","w"))==NULL){
		printf("���ļ�ʧ�ܣ�\n");
		return 0;
	}
	//8.2.д�ļ�
	for(i = 0; i <= maxIndex; i++ ){
		fprintf(fp,"%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
			Spends[i].month,
			Spends[i].season,
			Spends[i].foodSpend,
			Spends[i].phoneSpend,
			Spends[i].bookSpend,
			Spends[i].otherSpend,
			Spends[i].workStudyIncome,
			Spends[i].totalSpend,
			Spends[i].state);
	}
	//8.3�ر��ļ�
	fclose(fp);
	return 1;
}

//9.�Զ������·�
//�������ܣ��Զ������·ݣ������1�£��·���1�����򷵻���һ��+1
//��������
//����ֵ���·�
int createMonth(){
	if(maxIndex == 0){
		return 1;
	}else{//������һ��+1
		return Spends[maxIndex-1].month + 1;
	}
}

//10.�����·ݲ�������
//�������ܣ������·ݲ�ѯѧ����������Ϣ�������е�����λ��
//�������·�
//����ֵ����ѧ����������Ϣ�������е�����������ҵ��˷���������
//���û�ҵ�������-1
int findIndex(int month){
	int index = -1;
	for(int i = 0; i <= maxIndex; i++){
		//��֤ѧ����У״̬����
		if(Spends[i].state == 1){
			if(Spends[i].month == month){
				//��¼��ǰ����
				index = i;
				break;
			}
		}		
	}
	return index;
}

//11.��ʾ��ǰѧ����������Ϣ
//�������ܣ���ӡ��ǰ������ѧ����������Ϣ
//�����������е�����
//����ֵ����
void printCurrentSpend(int index){
	printf("|---------------------------------------------------------------------------|\n");
	printf("|%-8s|%-8s|%-8s|%-8s|%-8s|%-8s|%-12s|%-8s|\n",
		"�·�","����","�Է�����","�绰����","��������","��������","�ڹ���ѧ����","����֧��");
	printf("|--------+--------+--------+--------+--------+--------+------------+--------|\n");
	printf("|%-8d|%-8s|%-8d|%-8d|%-8d|%-8d|%-12d|%-8d|\n",
		Spends[index].month,
		Spends[index].season,
		Spends[index].foodSpend,
		Spends[index].phoneSpend,
		Spends[index].bookSpend,
		Spends[index].otherSpend,
		Spends[index].workStudyIncome,
		Spends[index].totalSpend);
	printf("|---------------------------------------------------------------------------|\n");
}

//12.��ӭ����
int welcome(int y){
	//int y;
	printf("----------------------------------------\n");
	printf("  ��ӭʹ��");
	printf("%d",y);
	printf("���ѧ���������ѹ���ϵͳ   \n");
	printf("----------------------------------------\n");
	printf("\n");
	return 0;
}

//13.���˵�
void mainMenu(){
	//ѭ����ʾ
	int select = 0;//����ѡ��
	while(true){
		printf("----------------------------------------\n");
		printf("          1.¼��ѧ����������Ϣ          \n");
		printf("          2.ɾ��ѧ����������Ϣ          \n");
		printf("          3.����ѧ����������Ϣ          \n");
		printf("          4.�޸�ѧ����������Ϣ          \n");
		printf("          5.��ӡѧ����������Ϣ          \n");
		printf("          6.ͳ��ѧ����������Ϣ          \n");
		printf("          0.�˳�ϵͳ                    \n");
		printf("----------------------------------------\n");
		printf("����������ѡ��\n");
		scanf("%d",&select);
		switch(select)
		{
		case 1://1.¼��ѧ����������Ϣ
			addStudentSpend();
			break;
		case 2://2.ɾ��ѧ����������Ϣ
			deleteStudentSpend();
			break;
		case 3://3.����ѧ����������Ϣ
			searchStudentSpend();
			break;
		case 4://4.�޸�ѧ����������Ϣ
			updateStudentSpend();
			break;
		case 5://5.��ӡѧ����������Ϣ
			printfStudentSpend();
			break;
		case 6://6.ѧ����������Ϣ����
			analysisSyudentSpend();
			break;
		case 0://0.�˳�ϵͳ
			exit(0);
		default:
			printf("����ѡ������������ѡ��\n");
		}
	}
}

//������
void main()
{
	int year;
	printf("�����������¼�����ѵ���ݣ�");
	scanf("%d",&year);
	printf("%d",year);
	printf("���ѧ�����Ѽ�¼��\n");
	welcome(year);
	maxIndex = readData();
	mainMenu();
	system("pause");
}




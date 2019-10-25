#include<iostream>
#include<vector>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

class RingQueue{	//���ź���ʵ��ͬ��
private:
	std::vector<int> _queue;
	int _capacity;
	int _customer_step;
	int _productor_step;
	sem_t _sem_mutex; //���ź���ʵ�ֻ���,����0��1
	//pthread_mutex_t _mutex;
	sem_t _idel_space;//�������ж���ʣ��ռ�
	sem_t _data_space;//�����ж��ٿռ�������
private:
	void QueueLock(){
		sem_wait(&_sem_mutex);
		//pthread_mutex_lock(&_mutex);
	}
	void QueueUnLock(){
		sem_post(&_sem_mutex);
		//pthread_mutex_unlock(&_mutex);
	}
	void CustomerWait(){
		//int sem_wait(sem_t* sem)
		//�����ж�,��<=0;�������ȴ�
		//int sem_trywait(sem_t *sem)
		//�����ж�,��<=0;�򱨴���
		//int sem_timedwait(sem_t* sem,const struct timespec *abs_timeout)
		//�����ж�,��<=0;����ʱ�ȴ�
		sem_wait(&_data_space);
	}
	void CustomerWakeUp(){
		//int sem_post(sem_t* sem);
		sem_post(&_data_space);
	}
	void ProductorWait(){
		sem_wait(&_idle_space);
	}
	void ProductorWakeUp(){
		sem_post(&_data_space);
	}
	//��Ϊ�ź����Ѿ����ڲ������������ж�����
	//void QueueIsFull()��void QueueIsEmpty()��û����
public:
	RingQueue(int cap = 10) :_capacity(cap){
		_productor_step = 0;
		_customer_step = 0;
		//int sem_init(sem_t* sem,int pshared,unsigned int value);
		//����:
		//sem  �ź���
		//pshared:	0  �����̼߳�ͬ���뻥��	;	!0	���ڽ��̼�ͬ���뻥��
		//value:  �ź����ļ�����ֵ
		sem_init(&_sem_mutex, 0, 1);//�ź���ʵ�ֻ���,����ֻ��Ϊ0��1
		//pthread
		sem_init(&_idle_space, 0, _capacity);
		sem_init(&_data_space, 0, 0);
	}
	~RinQueue(){
		sem_destroy(&_sem_mutex);
		//pthread_mutex_destroy(&_mutex);
		sem_destroy(&_idel_space);
		sem_destroy(&_data_space);
	}
	void QueuePush(int data){
		ProductorWait();
		QueueLock();
		_queue[_productor_step] = data;
		_productor_step++;
		_productor_step %= _capacity;
		QueueUnLock();
		CustomerWakeUp();
	}
	void QueuePop(int* data){
		CustomerWait();
		QueueLock();
		*data = _queue[_customer_step];
		_customer_step++;
		_customer_step %= _capacity;
		QueueUnLock();
		ProductorWakeUp();
	}
};

void* thr_productor(void *arg){
	RingQueue *q = (RingQueue*)arg;
	int i = 0;
	while (1){
		q->QueuePush;
		printf("put-------data:%d\n", i);
		i++;
	}
	return NULL;
}

void* thr_consumer(void *arg){
	RingQueue *q = (RingQueue*)arg;
	while (1){
		int data;
		q->QueuePop(&data);
		printf("get-------data:%d\n", data);
	}
	return NULL;
}

int main(void){
	int i, ret;
	pthread_t ctid[4], ptid[4];
	RingQueue q;
	
	for (i = 0; i < 4; i++){
		ret = pthread_create(&ptid[i], NULL, thr_productor, (void*)&q);
		if (ret != 0){
			printf("thread create error\n");
			return -1;
		}
	}

	for (i = 0; i < 4; i++){
		ret = pthread_create(&ctid[i], NULL, thr_productor, (void*)&q);
		if (ret != 0){
			printf("thread create error\n");
			return -1;
		}
	}
	return 0;
}
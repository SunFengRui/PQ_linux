#include <pcap.h>
#include <stdlib.h>
#include "workthread.h"

#if(AD_SAMPLE_ACCURACY==16)
static char packet_filter[] = "ip and udp and ether[29] & 0xff = 0x0a";
#else
static char packet_filter[] = "ether[12] =0x88 and ether[13] = 0xbb";
#endif

void *Pcap1ThreadFunc(void *arg)
{
  (void)(arg);
  int i=0;
  char errBuf[PCAP_ERRBUF_SIZE];
  pcap_if_t *alldevs,*d;
  /* get a device */
  //devStr = pcap_lookupdev(errBuf);
  pcap_findalldevs(&alldevs,errBuf);

for(d=alldevs;d;d=d->next)
{
    printf("%d. %s\n",++i,d->name);
    //if(d->description)
    //printf(" (%s)\n",d->description);

}
//for(d=alldevs,i=0;i<inum-1;d=d->next,i++);

  /* open a device, wait until a packet arrives */
//pcap_t * pcap_open_live(const char * device, int snaplen, int promisc, int to_ms, char * errbuf)
//1表示混杂模式
//0表示一直等到数据包来

  pcap_t * device = pcap_open_live("enp1s0", 65535, 1, 0, errBuf);

  if(!device)
  {
    printf("error: pcap_open_live(): %s\n", errBuf);
    exit(1);
  }

  /* construct a filter */
  struct bpf_program filter;
/*
src host 192.168.1.177
只接收源ip地址是192.168.1.177的数据包
dst port 80
只接收tcp/udp的目的端口是80的数据包
not tcp
只接收不使用tcp协议的数据包
tcp[13] == 0x02 and (dst port 22 or dst port 23)
只接收SYN标志位置位且目标端口是22或23的数据包（tcp首部开始的第13个字节）
icmp[icmptype] == icmp-echoreply or icmp[icmptype] == icmp-echo
只接收icmp的ping请求和ping响应的数据包
ehter dst 00:e0:09:c1:0e:82
只接收以太网mac地址是00:e0:09:c1:0e:82的数据包
ip[8] == 5
只接收ip的ttl=5的数据包（ip首部开始的第8个字节）
*/
  pcap_compile(device, &filter, packet_filter, 1, 0);
  pcap_setfilter(device, &filter);
  //printf("A listening on %s....%d\n",d->name,inum);
  /* wait loop forever */
  int id = 0;
  //-1表示永远抓包
  pcap_loop(device, -1, ethernet_protocol_packet_callback_A, (u_char*)&id);

  pcap_close(device);

  return nullptr;
}
void *Pcap2ThreadFunc(void *arg)
{
  (void)(arg);
  char errBuf[PCAP_ERRBUF_SIZE];
  /* get a device */
  //devStr = pcap_lookupdev(errBuf);

//for(d=alldevs,i=0;i<inum2-1;d=d->next,i++);

  /* open a device, wait until a packet arrives */
//pcap_t * pcap_open_live(const char * device, int snaplen, int promisc, int to_ms, char * errbuf)
//1表示混杂模式
//0表示一直等到数据包来

  pcap_t * device = pcap_open_live("enp2s0", 65535, 1, 0, errBuf);

  if(!device)
  {
    printf("error: pcap_open_live(): %s\n", errBuf);
    exit(1);
  }

  /* construct a filter */
  struct bpf_program filter;

  pcap_compile(device, &filter, packet_filter, 1, 0);
  pcap_setfilter(device, &filter);
  //printf("B listening on %s....%d\n",d->name,inum2);
  /* wait loop forever */
  int id = 0;
  //-1表示永远抓包
  pcap_loop(device, -1, ethernet_protocol_packet_callback_B, (u_char*)&id);
  pcap_close(device);
  return nullptr;
}
void *Pcap3ThreadFunc(void *arg)
{
  (void)(arg);

  char errBuf[PCAP_ERRBUF_SIZE];
  /* get a device */
  //devStr = pcap_lookupdev(errBuf);


//for(d=alldevs,i=0;i<inum3-1;d=d->next,i++);

  /* open a device, wait until a packet arrives */
//pcap_t * pcap_open_live(const char * device, int snaplen, int promisc, int to_ms, char * errbuf)
//1表示混杂模式
//0表示一直等到数据包来

  pcap_t * device = pcap_open_live("enp3s0", 65535, 1, 0, errBuf);

  if(!device)
  {
    printf("error: pcap_open_live(): %s\n", errBuf);
    exit(1);
  }

  /* construct a filter */
  struct bpf_program filter;

  pcap_compile(device, &filter, packet_filter, 1, 0);
  pcap_setfilter(device, &filter);
 // printf("C listening on %s....%d\n",d->name,inum3);
  /* wait loop forever */
  int id = 0;
  //-1表示永远抓包
  pcap_loop(device, -1, ethernet_protocol_packet_callback_C, (u_char*)&id);

  pcap_close(device);

  return nullptr;
}

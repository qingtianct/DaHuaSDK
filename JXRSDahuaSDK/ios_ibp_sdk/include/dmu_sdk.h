/**
 * Copyright (c) 2014, �㽭��ϵͳ�������޹�˾ All rights reserved.
 * \file		dmu_sdk.h
 * \brief		dmu_sdk
 * \author		24997
 * \date		2014��12��19��
 * \note		DMU SDK �ӿ�
 */
#ifndef IBP_DMU_SDK_H
#define IBP_DMU_SDK_H

#if !defined(t_uint32)
typedef unsigned int t_uint32;
#endif

#if !defined(t_int32)
typedef int t_int32;
#endif

#if !defined(t_float32)
typedef float t_float32;
#endif

#ifdef WIN32
#ifdef IBPDMUSDK_LIB_EXPORTS
#define DLIB_API __declspec(dllexport)
#else
#define DLIB_API __declspec(dllimport)
#endif  //DLIB_EXPORTS
#define CALLBACK __stdcall
#else
#define DLIB_API
#define CALLBACK
#endif   //WIN32

#ifdef __cplusplus
extern "C" 
{
#endif

/**
* @defgroup DMU_SDK����
* @{
*/

#pragma region ͨ�ù���



/**
* @defgroup DMU_SDKϵͳ
* @{
*/

/**
@brief DMU_SDK��ʼ��
@return 
@remarks
@see 
*/
DLIB_API t_int32 DMU_SC_Init();


/**
@brief DMU_SDK��ʼ��,��������Ѿ�����applicationBase�ĳ������
@return 
@remarks
@see DMU_SC_InitNoApp
*/
DLIB_API t_int32 DMU_SC_InitNoApp();

/**
@brief DMU_SDK��ʼ��,������
@return 
@remarks
@see 
*/
DLIB_API t_int32 DMU_SC_InitSingle();

/**
@brief DMU_SDK����ʼ��
@return 
@remarks
@see 
*/
DLIB_API t_int32 DMU_SC_Cleanup();

/** @} */

/**
* @defgroup DMU_SDK���ӷ���
* @{
*/

/**
@brief ����DMU����
@param [in]  timeout		��ʱʱ��
@param [in]  cmusession		CMU��½���
@param [in]  ipinfo		    DMU�����ip��Ϣ
@param [in]  svrdomid		DMU�������id
@param [in]  serverid		DMU����id
@param [out] outxml			������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<handle></handle>		���ӳɹ����صľ��
</root>
@endverbatim
@param [in]  maxlen			��Ϣ��󳤶�
@return 
@remarks
@see 
*/
DLIB_API t_int32 DMU_AC_Connect(t_uint32 cmusession, char* ipinfo, char* svrdomid, t_int32 serverid, char* outxml, t_uint32 maxlen);

/**
@brief �û���֤����DMU����
@param [in]  timeout		��ʱʱ��
@param [in]  usersession	�û���֤
@param [in]  ipinfo		    DMU�����ip��Ϣ
@param [in]  svrdomid		DMU�������id
@param [in]  serverid		DMU����id
@param [out] outxml			������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<handle></handle>		���ӳɹ����صľ��
</root>
@endverbatim
@param [in]  maxlen			��Ϣ��󳤶�
@return 
@remarks
@see 
*/
DLIB_API t_int32 DMU_AC_ConnectNoCmu(t_uint32 usersession, char* ipinfo, char* svrdomid, t_int32 serverid, char* outxml, t_uint32 maxlen);

/**
* @defgroup DMU_SDKͬ������
* @{
*/
/**
@brief ͬ������dmu
@param [in] cmuLoginHandle	cmu��֤session
@param [in] timeout			��ʱʱ��
@param [in] ipInfo			dmu����ip��Ϣ
@param [in] svrDomId		������id
@param [in] svrId			����id
@param [in] maxLen			xmlOutput����
@param [out] xmlOutput		xml���
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
<dmusession>2</dmusession>
</root>
@endverbatim
@return						200 �ɹ�,��������������ĵ� 
@remarks
@see 
*/
DLIB_API t_int32 DMU_SC_Connect(t_uint32 cmuLoginHandle, t_int32 timeout, char *ipInfo, char *svrDomId, t_int32 svrId, char *outxml, t_uint32 maxlen);


/**
@brief �Ͽ�DMU����
@param [in]  session		���Ӿ��
@return 
@remarks
@see 
*/
DLIB_API t_int32 DMU_SC_Disconn(t_uint32 session);

/** @} */

/**
* @defgroup DMU_SDK�ص�����
* @{
*/

/**
@brief ��Ϣ�ص�����
@param [in] session		���Ӿ��
@param [in] data		��Ϣ����
@param [in] bufSize	    ���ݳ���
@param [in] pUser		�û��Զ�������
@return 
@remarks
@see 
*/
typedef t_int32 (*fIbpDmuMsgCallBack)(t_uint32 session, char *data, t_uint32 bufSize, void* pUser);

/**
@brief ������Ϣ�ص�����
@param [in] session		���Ӿ��
@param [in] cb			�ص�����
@param [in] pUser		�û�����
@return 
@remarks �ص���Ϣʾ��
@verbatim
����online��Ϣ֪ͨ
<?xml version='1.0' encoding='utf-8' ?>
<root version="1.0" unit="DMU" type="onlineNotify" cmd="onlineNotify" sequence="0" length="0">
	<server 
		servername="" 			��������
		session="" 				������
		status="" 				������״̬
	/>
</root>
@endverbatim
@verbatim
����master����֪ͨ
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="reportMasterUpdate" sequence="" session="0">
	<domid></domid>				��ID
	<modulename></modulename>	ģ������
</root>
@endverbatim
@verbatim
�澯����֪ͨ
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="alarmData" sequence="">
	<item
		domid=""				��ID
		devcode=""				�豸����
		devname=""				�豸����
		subdevcode=""			���豸����
		name=""					���豸����
		chncode=""				��Դ��ͨ������
		chnname=""				��Դ��ͨ������
		chnidx=""				��Դ��ͨ������
		type=""					�澯����
		subtype=""				�澯������
		status=""				״̬
		level=""				�澯�ȼ� 0 �� 1 ���� 2 ��Ҫ 3 һ�� 4 ��Ҫ 5��ͨ
		alarmtime=""			�澯�ϱ�ʱ��
		msgtxt=""				��Ϣ����
		val=""					ֵ
		unit=""					��λ
		orgpath=""				��֯�豸·��
		title=""				��֯�豸·����
		longitude=""            ����(��λ�ǰ����֮�ȣ���Χ0-360��)
		latitude=""             γ��(��λ�ǰ����֮�ȣ���Χ0-180��)
		phonedomid=""			������
		phonecode=""			��������
		phonenum=""				��������
		phonepass=""			��������
	/>
</root>
@endverbatim
@verbatim
ʵʱ����֪ͨ
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="realData" sequence="">
	<item
		domid=""				��ID
		devcode=""				�豸����
		subdevcode=""			���豸����
		chncode=""				ͨ������
		chnidx=""				ͨ������
		val=""					ֵ
		unit=""					��λ
		desc=""					����
		time=""					ʱ��
		isalarm=""				�Ƿ�澯
		type=""					�澯����
		level=""				�澯�ȼ�
		orgpath=""			
		title=""
		phonedomid=""			������
		phonecode=""			��������
		phonenum=""				��������
		phonepass=""			��������

		intparam1=""			gps��λ����
		intparam2=""			gps����״̬(true �ã�false ��)
		intparam3=""			gps��λ״̬(true ��λ��false ����λ)
		strparam1=""
		strparam2=""
		strparam3=""
	>
		<expand					    pgs��չ��Ϣ
			longitude=""			����(��λ�ǰ����֮�ȣ���Χ0-360��)
			latitude=""				γ��(��λ�ǰ����֮�ȣ���Χ0-180��)
			height=""				�߶�(��)
			angle=""				�����(��������Ϊԭ�㣬˳ʱ��Ϊ��)
			speed=""				�ٶ�(��λ�Ǻ��speed/1000*1.852����/Сʱ)
		/>
	</item>
</root>
@endverbatim
@verbatim
�޸�Ԥ�õ�֪ͨ
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="modifyPrepointNotify" sequence="">
	<domid></domid>				��ID
	<devcode></devcode>			�豸����
	<index></index>				Ԥ�õ��
	<name></name>				����
	<operate></operate>			��������
	<userid></userid>			�û�ID
	<username></username>		�û�����
	<level>1</level>			�û�����
	<updatetime></updatetime>	����ʱ��
</root>
@endverbatim
@verbatim
�޸�OSD֪ͨ
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="modifyOSDNotify" sequence="">
	<opt 
		domid="" 				��ID
		devcode="" 				�豸����
		userid="" 				�û�ID
		operate="" 				��������
		count=""				��������
	>
		<info 
			type="" 			�޸����� 1 �޸�OSD��ǩ 2 �޸�OSDʱ��
			pointx="" 			ԭ��X����
			pointy="" 			ԭ��Y����
			width="" 			���
			length="" 			�߶�
			rgb="" 				RGBֵ
			alpha="" 			ALPHAֵ
			title=""			��ǩ����
		/>
	</opt>
</root>
@endverbatim
@verbatim
��̨��ռ֪ͨ
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="ptzArrange" sequence="">
	<domid></domid>				��ID
	<chncode></chncode>			ͨ������
	<userid></userid>			�û�ID
	<username>0</username>		�û��� 
	<level></level>				�û�����
	<department></department>	����
	<locktime></locktime>		����ʱ��
</root>
@endverbatim
@verbatim
��ѯ�������豸���֪ͨ
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="searchDevRetNotify" sequence="">
	<devcode>abc</devcode>
	<type>1</type>
	<ip></ip>
	<port>1</port>
	<mac></mac>
</root>
@endverbatim

2018.6.26 xmchen add begin  ��λ��ػص�����
@verbatim
�붨λ������֮�����·����״̬
<?xml version='1.0' encoding='utf-8' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="onlineNotify" sequence="">
	<domid></domid>				        ��ID
	<deviceType></deviceType>		        �豸����
	<terminalCode></terminalCode>		   �豸����
	<linkStatus></linkStatus>              0-�Ͽ� 1-����
	<version></version>                    ��������汾���Ͽ�ʱ��Ч
	<date></date>                          ���ڣ��Ͽ�ʱ��Ч
	<userid></userid>                      �û�����Ӧ��id������ʱ�ɶ�λ���������أ��Ͽ�ʱ��Ч
</root>
@endverbatim

@verbatim
��λ����֪ͨ
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="posDataNotify" sequence="">
	<domid></domid>				       ��ID
	<deviceType></deviceType>		       �豸����
	<linkStatus></linkStatus>             0-�Ͽ� 1-����
	<sequence></sequence>                 ���кţ�������ϵͳ����Ψһ�ģ��������û�ID��(4λ10������,��¼���ã���UTC���ڴ���14λ10����������ʽ yyyymmddhhmmss����5λΨһ��ʮ�������кŴ������ɣ��磺01992009013011552311111��
	<terminalCode></terminalCode>         �ն˺���
	<terminalType></terminalType>         ͨ���ն����ͣ�1-�������� 2-���� 3-���� 4-AIS 5-GSM 6-GSM�ֻ��� 7-�̲� 8-���̲� 9-RFID 10-�״�Ŀ��
	<posType></posType>                   λ������, ���ͽ϶࣬����鿴�ĵ���3  
	<utc></utc>                           GPSʱ��: ��1970-01-01 00:00:00����������
	<longitude></longitude>               ���ȣ���λ: 1/10000��
	<latitude></latitude>                 γ�ȣ���λ: 1/10000��
	<course></course>                     ���򣬵�λ: 1/10��
	<trueHeading></trueHeading>           �����򣬵�λ: 1/10��
	<speed></speed>                       �ٶȣ���λ: 1/10��
	<status></status>                     ״̬�룬0-���� 1-�ն˹���
	<vdesc></vdesc>                       ��ע������д����ԭ�򣬻�������λ��Я���ĸ�����Ϣ��
</root>
@endverbatim

@verbatim
��������֪ͨ
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="smsDataNotify" sequence="">
<root>
	<domid></domid>				        ��ID
	<deviceType></deviceType>		            �豸����
	<sequence></sequence>                  ���кţ�������ϵͳ����Ψһ�ģ��������û� ID��(4λ10������,��¼���ã���UTC���ڴ���14λ10����������ʽ yyyymmddhhmmss����5λΨһ��ʮ�������кŴ������ɣ��磺01992009013011552311111��
	<terminalCodeSrc></terminalCodeSrc>    ͨ��Դ�ն˴��롣����Ϊ�ƶ��ն�ͨ�������ID
	<terminalTypeSrc></terminalTypeSrc>    Դͨ���ն����ͣ�1-�������� 2-���� 3-���� 4-AIS 5-GSM 6-GSM�ֻ��� 7-�̲� 8-���̲� 9-RFID 10-�״�Ŀ��
	<terminalCodeDst></terminalCodeDst>    ͨ��Ŀ���ն˴��롣����Ϊ�ƶ��ն�ͨ�������ID
	<terminalTypeDst></terminalTypeDst>    Ŀ��ͨ���ն����ͣ�1-�������� 2-���� 3-���� 4-AIS 5-GSM 6-GSM�ֻ��� 7-�̲� 8-���̲� 9-RFID 10-�״�Ŀ��
	<msgType></msgType>                    �������Ͷ��� 0-��ͨ��Ϣ 1-������Ϣ
	<utc></utc>                            GPSʱ��: ��1970-01-01 00:00:00����������
	<msg></msg>                            ��Ϣ����
</root>
@endverbatim
2018.6.26 xmchen add end ��λ��ػص�����
@see 
*/
DLIB_API t_int32 DMU_SC_SetDmuMsg(t_uint32 session, fIbpDmuMsgCallBack cb, void* pUser);

/**
@brief ���ûص��澯���ݻ�������
@param [in] session		���Ӿ��
@param [in] num			�澯����(Ĭ������100��)
@return
@remarks
@see 
*/
DLIB_API t_int32 DMU_SC_SetAlarmDataCfg(t_uint32 session, t_int32 num);

/**
@brief ��ѯ���»ص��澯����
@param [in] session		���Ӿ��
@param [out] outxml		������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<item 
		domid=""			��ID
		devcode=""			�豸����
		devname=""			�豸����
		subdevcode=""		���豸����
		name=""				���豸����
		chncode=""			��Դ��ͨ������
		chnname=""			��Դ��ͨ������
		chnidx=""			��Դ��ͨ������
		type=""				�澯����
		subtype=""			�澯������
		status=""			״̬
		level=""			�澯�ȼ�
		alarmtime=""		�澯�ϱ�ʱ��
		msgtxt=""			��Ϣ����
		val=""				ֵ
		unit=""				��λ
		orgpath=""			��֯�豸·��
		title=""			��֯�豸·����
	/>
</root>
@endverbatim
@param [in]  maxlen		��Ϣ��󳤶�
@return
@remarks
@see 
*/
DLIB_API t_int32 DMU_SC_QueryNewAlarmData(t_uint32 session, char *outxml, t_uint32 maxlen);

/**
@brief ���ûص����豸�����ߵĸ澯��Ϣ
@param [in] session		���Ӿ��
@param [in] flag		�ص���ʶ 0 Ĭ�ϲ��ص� 1 �ص�
@return
@remarks �����ʵʱ�ص��澯��Ϣ������ô˽ӿ�
@see 
*/
DLIB_API t_int32 DMU_SC_OpenCbAlarmData(t_uint32 session, t_int32 flag);

/** @} */

/**
* @defgroup DMU_SDK�澯����
* @{
*/

/**
@brief ���ö���ȫ���澯��ʵʱ���ݱ�ʶ
@param [in] session				���Ӿ��
@param [in] subscribeflag		�澯ȫ�����ı�ʶ 0 Ĭ�Ϸ� 1 ��
@param [in] distributeflag		�ַ��豸��Ȩ��ʶ 0 �� 1 Ĭ����
@return
@remarks 1��Ĭ��ʱ��������ô˽ӿ� 2������Ҫ�����ӳɹ�����������
@see 
*/
DLIB_API t_int32 DMU_SC_SetSubAllAlarm(t_uint32 session, t_int32 subscribeflag = 0, t_int32 distributeflag = 1);

/**
@brief �����澯��ʵʱ���ݶ���
@param [in] session		���Ӿ��
@param [in] timeout		��ʱʱ��
@param [in] info		����xml
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<opt
		type=""			������ 0 �澯���� 1 ʵʱ���ݶ��� 2pgs��Ϣ 
		level=""		���и澯�ȼ� -1 ��ʾ���ĸ澯 1~5���ĵȼ�ͳһ�޸�λ�õȼ�
	>
		<item 
			operate=""	��������
			flag=""		0�����ľ�����豸��1��������֯��2:����ͨ��
			devcode=""	�豸����(Ϊ��֯ʱ����д·��)
			domid=""	�豸��ID
			type=""		�澯���� -1 ��������
			level=""	�澯�ȼ� 5 ���ڵ��ڸõȼ��ĸ澯�������յ�
		/>
		....

	</opt>
</root>
@endverbatim
@return
@remarks ������֯���Ƕ�����֯�����������豸
@see 
*/
DLIB_API t_int32 DMU_SC_OptSubscribe(t_uint32 session, t_int32 timeout, char *info);


/**
@brief �����澯��ʵʱ���ݶ��ģ������û���
@param [in] session		���Ӿ��
@param [in] timeout		��ʱʱ��
@param [in] info		����xml
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<opt
		type=""			������ 0 �澯���� 1 ʵʱ���ݶ��� 2pgs��Ϣ 3 �����û��澯
		level=""		���и澯�ȼ� -1 ��ʾ���ĸ澯 1~5���ĵȼ�ͳһ�޸�Ϊ�õȼ�
		userid=""       �����û���useid
	>
		<item 
			operate=""	��������
			flag=""		0�����ľ�����豸��1��������֯; 2 ����ͨ��; 
			flaguser=""	0 �����û� 1 �����û���֯
			devcode=""  �豸���루������֯ʱ����֯·�� 0-1-��
			userid=""	�������û�id(Ϊ��֯ʱ�������orgpath��д·��)
			orgpath=""  �������û���֯·��
			domid=""	��ID
			type=""		�澯���� -1 ��������
			level=""	�澯�ȼ� 5 ���ڵ��ڸõȼ��ĸ澯�������յ�
		/>
		......
	</opt>
</root>
@endverbatim
@return
@remarks ������֯���Ƕ�����֯�����������û�
@see 
*/
DLIB_API t_int32 DMU_SC_OptSubscribeUser(t_uint32 session, t_int32 timeout, char *info);

/**
@brief ��ѯ�û��澯��ʵʱ���ݶ���
@param [in] session		���Ӿ��
@param [in] timeout		��ʱʱ��
@param [in] subtype		������ 0 �澯���� 1 ʵʱ���ݶ��� 2 �豸GPS�澯 3 �û��澯
@param [in] userid		�����û�userid��userId=0 �������û���userId!=0��ָ���û���
@param [out] outxml		������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<item 
		userid=""		�û�ID
		devcode=""		�豸����
		domid=""		�豸��ID
		type=""			�澯����
		level=""		�澯�ȼ�
	/>
</root>
@endverbatim
@param [in]  maxlen		��Ϣ��󳤶�
@return
@remarks
@see 
*/
DLIB_API t_int32 DMU_SC_QuerySubscribe(t_uint32 session, t_int32 timeout, t_int32 subtype, t_int32 userid, char *outxml, t_uint32 maxlen);


/**
@brief ��ѯ�û��澯��ʵʱ���ݶ���
@param [in] session		���Ӿ��
@param [in] timeout		��ʱʱ��
@param [in] subtype		������ 0 �澯���� 1 ʵʱ���ݶ���
@param [out] outxml		������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<item 
		userid=""		�û�ID(���ﶩ�Ĳ�ѯ)��userId=0 �������û���userId!=0��ָ���û���
		devcode=""		�豸����
		domid=""		�豸��ID
		type=""			�澯����
		level=""		�澯�ȼ�
	/>
</root>
@endverbatim
@param [in]  maxlen		��Ϣ��󳤶�
@return
@remarks
@see 
*/
//DLIB_API t_int32 DMU_SC_QueryUserSubscribe(t_uint32 session, t_int32 timeout, t_int32 subtype, char *outxml, t_uint32 maxlen);

/** @} */

/**
* @defgroup DMU_SDK��ѯ�澯����
* @{
*/

/**
@brief ��ѯ��ʷ�澯��Ϣ
@param [in]  session			���Ӿ��
@param [in]  timeout			��ʱʱ��
@param [in]	 info				������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<srcdomid />		������ID
	<starttime />		��ʼʱ��
	<endtime />			����ʱ��
	<type />			�澯���� -1 ��ѯȫ�� ������ѯָ��
	<domid />			�豸��ID
	<devcode />			ͨ���豸���룬����"'chn0','chn1','chn2'"
	<chnidx />			ͨ�����
	<domdevcode />		�豸��ID+�豸���룬����"'chn0','chn1','chn2'@domid1; 'chn0','chn1','chn2'@domid2"
	<size />			ÿҳ��С
	<curpage />			��ѯ�ڼ�ҳ
	<orgcode />		    ��֯����(orgcode��devcodeֻ�ܴ���һ��)
</root>
@endverbatim
@param [out] outxml				������Ϣ

// ע��devcode��������豸�澯��devcode�����豸����
// �����ͨ���澯��devcode����ͨ������

@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total></total>				����
	<item 
		id=""					�澯��¼ID
		domid=""				��ID
		devcode=""				�豸����
		devname=""				�豸����
		chnidx=""				ͨ������
		devtype=""				�豸����
		type=""					�澯����
		status=""				״̬
		level=""				�澯�ȼ�
		alarmtime=""			�澯ʱ��
		length=""				���ݳ���
		msgtxt=""				��Ϣ�ı�
		confirmor=""			ȷ����
		confirmtime=""			ȷ��ʱ��
		confirmmsg=""			ȷ����Ϣ
		confirmstatus=""		ȷ��״̬
	/>
	...
</root>
@endverbatim
@param [in]  maxlen				��Ϣ��󳤶�
@return
@remarks
@see
*/
DLIB_API t_int32 DMU_SC_QueryHistoryAlarmInfo(t_uint32 session, t_int32 timeout, char *info, char *outxml, t_uint32 maxlen);

/**
@brief �����澯ȷ����Ϣ
@param [in]  session			���Ӿ��
@param [in]  timeout			��ʱʱ��
@param [in]	 info				������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<confirmtime></confirmtime>	�澯��Ϣ����(����澯ʱ��)
	<item 
		id=""					�澯��¼ID
		confirmmsg=""			ȷ����Ϣ
		confirmstatus=""		ȷ��״̬ 0 δȷ�� 1 ��ȷ��
	/>
</root>
@endverbatim
@return
@remarks
@see
*/
DLIB_API t_int32 DMU_SC_OptAlarmConfirm(t_uint32 session, t_int32 timeout, char *info);


/**
@brief ���������û��澯ȷ����Ϣ
@param [in]  session			���Ӿ��
@param [in]  timeout			��ʱʱ��
@param [in]	 info				������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total><total>                 		����
	<confirmmsg><confirmmsg>			ȷ���������
	<item
		revalarmusername=""				�����û�����
		revalarmuserid=""				�����û�id
		username=""						�澯�û����ƣ������DB��
		userid=""						�澯�û�id
		domid=""                        �澯��ID
		devcode=""                      �澯�豸����
		chncode=""						�澯ͨ������
		orgpath=""                      ��֯·���������DB��
		devtype=""                      �豸����
		type=""							�澯����
		guid=""							�澯guid 
		ackstatus=""                    �澯״̬ȷ�ϣ�1���澯�Ѵ���  5�������ٻ�   6�������Ѵ���  7������ ��ö��ֵ�������ѯ�Ķ�Ӧ��----������������
	/>
	......
</root>
@endverbatim
@return
@remarks
@see
*/
DLIB_API t_int32 DMU_SC_OptBatchPhoneAlarmConfirm(t_uint32 session, t_int32 timeout, char *info);

/**
@brief ��ѯ�����澯��Ϣ
@param [in]  session                       ���Ӿ��
@param [in]  timeout                      ��ʱʱ��
@param [in]    info                                     ������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
         <srcdomid />             ������ID
         <starttime />            ��ʼʱ�䣺2016-05-10 00:00:00
         <endtime />              ����ʱ��
         <type />                 �澯���� -1 ��ѯȫ�� ������ѯָ��4,201
         <domid />                �豸��ID
         <status />               ״̬����ѯ�澯״̬,0��δ����1�Ǵ���
         <size />                 ÿҳ��С
         <curpage />              ��ѯ�ڼ�ҳ,1��ʾ��һҳ
		 <confirmstatus />        �澯�û�ȷ��״̬
		 <flaguser  />            1:subuserid���Ǹ澯�û���userid,��alarm_log�����Ѿ����͵ĸ澯״̬��0����ѯ�û�subuserid�ĸ澯�������subuserid���Ӧ�û�userid
		 <subuserid />            �����û�ID,���ݶ����û���ID���飬subuserid<=0 �Ͱ���ԭ�ȵ���ͨ��ѯ��subuserid>0���ݶ��Ĳ�ѯ
		 <devtype />              �豸���� -1 ��ѯȫ�� ������ѯָ�����֣���ʽ�磺27,111,102,301
		 <flag />                 0:�������ʱ��������ѯ��1��ѯ��������ȥ24Сʱ������
		 <flagtime />             0:���յȼ�ʱ�������ѯ��1�����յȼ������ѯ,2����ʱ�������ѯ��3����ʱ��ȼ�����    ��ע��Ĭ��ʱ�����򣬵ȼ���������
</root>
@endverbatim
@param [out] outxml                                  ������Ϣ

// ע��devcode��������豸�澯��devcode�����豸����
// �����ͨ���澯��devcode����ͨ������

@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
         <total></total>                                    ����
         <item 
                    id=""                                   �澯��¼ID
                   domid=""                                ��ID
                   devcode=""                              �豸����
                   devname=""                              �豸����
                   chnidx=""                               ͨ������
                   devtype=""                              �豸����
                   type=""                                 �澯����
                   status=""                               ״̬
                   level=""                                �澯�ȼ�
                   alarmtime=""                            �澯ʱ��
                   length=""                               ���ݳ���
                   msgtxt=""                               ��Ϣ�ı�
                   confirmor=""                            ȷ����
                   confirmtime=""                          ȷ��ʱ��
                   confirmmsg=""                           ȷ����Ϣ
                   comfirmstatus=""                        ȷ��״̬
				   guid=""                                 �澯guid
				   alarmstatus=""                          �澯״̬ȷ��   
         />
</root>
@endverbatim
@param [in]  maxlen                                 ��Ϣ��󳤶�
@return
@remarks
@see
*/
DLIB_API t_int32 DMU_SC_QueryAlarmCaseInfo(t_uint32 session, t_int32 timeout, char *info, char *outxml, t_uint32 maxlen);


/**
@brief ��ѯ��ʷʵʱ������Ϣ
@param [in]  session			���Ӿ��
@param [in]  timeout			��ʱʱ��
@param [in]  inxml				������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<srcdomid />		������ID
	<starttime />		��ʼʱ��
	<endtime />			����ʱ��
	<domid />			�豸��ID
	<devcode />			ͨ���豸���룬����"'chn0';'chn1';'chn2'"
	<size />			ÿҳ��С
	<curpage />			��ѯ�ڼ�ҳ
</root>
@endverbatim
@param [out] outxml				������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total></total>				����
	<item 
		domid=""				��ID
		devcode=""				�豸����
		devname=""				�豸����
		devtype=""				�豸����
		time=""					�ϱ�ʱ��
		val=""					ʵʱ����ֵ
		unit=""					ʵʱ���ݵ�λ
	/>
</root>
@endverbatim
@param [in]  maxlen				��Ϣ��󳤶�
@return
@remarks
@see
*/
DLIB_API t_int32 DMU_SC_QueryHistoryRealData(t_uint32 session, t_int32 timeout, char* inxml, char* outxml, t_uint32 maxlen);


/**
@brief ��ѯ��ʷʵʱ���ݵ�ƽ��ֵ
@param [in]  session			���Ӿ��
@param [in]  timeout			��ʱʱ��
@param [in]  inxml				������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<starttime />		��ʼʱ��
	<endtime />			����ʱ��
	<domid />			�豸��ID
	<devcode />			�豸����
	<interval />		�����ʱ�䣬��λ��
</root>
@endverbatim
@param [out] outxml				������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<item 
		domid=""				��ID
		devcode=""				�豸����
		devname=""				�豸����
		devtype=""				�豸����
		starttime=""			ʱ��ο�ʼʱ��
		endtime=""			    ʱ��ν���ʱ��
		val=""					ʱ��ε�ƽ��ֵ
		unit=""					ʵʱ���ݵ�λ
	/>
</root>
@endverbatim
@param [in]  maxlen				��Ϣ��󳤶�
@return
@remarks
@see
*/
DLIB_API t_int32 DMU_SC_QueryHistoryRealData_AVG(t_uint32 session, t_int32 timeout, char* inxml, char* outxml, t_uint32 maxlen);

/** @} */

/**
* @defgroup DMU_SDK�澯�ȼ�
* @{
*/

/**
@brief �����澯���ȼ�
@param [in] session				���Ӿ��
@param [in] timeout				��ʱʱ��
@param [in] info				������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<opt 
		operate=""				��������
	>
		<item 
			devcode=""			�豸����
			domid=""			��ID
			type=""				�澯����
			level=""			�澯�ȼ�
			updatetime=""		����ʱ��
		/>
	</opt>
</root>
@endverbatim
@return
@remarks
@see
*/
/** @} */



/** @} */

/**
* @defgroup DMU_SDK�ͻ��˸澯
* @{
*/
/**
@brief �ͻ�����dmu���Ϳͻ��˸澯
@param [in] session				���Ӿ��
@param [in] timeout				��ʱʱ��
@param [in] inxml				��ѯ�Ľ�����
@verbatim
��DMU_SC_SetDmuMsg�еĸ澯����֪ͨ
@endverbatim
@return
@remarks
@see
*/
DLIB_API t_int32 DMU_SC_SendClientAlarm(t_uint32 session, t_int32 timeout,char* inxml);

/**
@brief �ֻ��澯�ϱ���������Ŀ��
@param [in] session				���Ӿ��
@param [in] timeout				��ʱʱ��
@param [in] inxml				��ѯ�Ľ�����
@param [out] outguid			�澯ID
@param [in]  maxlen				��Ϣ��󳤶�
@verbatim
��DMU_SC_SetDmuMsg�еĸ澯����֪ͨ
@endverbatim
@return
@remarks
@see
*/
DLIB_API t_int32 DMU_SC_SendPhoneClientAlarm(t_uint32 session, t_int32 timeout,char* inxml,char* outguid,t_uint32 maxlen);

/** @} */

/**
* @defgroup DMU_SDKʵʱ����
* @{
*/
/**
@brief �ͻ�����dmu���Ϳͻ���ʵʱ����
@param [in] session				���Ӿ��
@param [in] timeout				��ʱʱ��
@param [in] inxml				gps��Ϣ
@verbatim
��DMU_SC_SetDmuMsg�е�ʵʱ����֪ͨ
@endverbatim
@return
@remarks
@see
*/
DLIB_API t_int32 DMU_SC_SendClientRealData(t_uint32 session, t_int32 timeout,char* inxml);
#ifdef __cplusplus
}
#endif

#endif



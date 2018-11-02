/**
 * Copyright (c) 2014~2015, �㽭��ϵͳ�������޹�˾ All rights reserved.
 * \file		cmu_sdk.h
 * \brief		cmu_sdk
 * \author		24997
 * \date		2014��12��19��
 * \note		CMU SDK �ӿ�
 */
#ifndef IBP_CMU_SDK_H
#define IBP_CMU_SDK_H

#if !defined(t_uint32)
typedef unsigned int t_uint32;
#endif

#if !defined(t_int32)
typedef int t_int32;
#endif

#if !defined(t_int64)
typedef long long t_int64;
#endif

#if !defined(t_float32)
typedef float t_float32;
#endif

#ifdef WIN32
#ifdef IBPCMUSDK_LIB_EXPORTS
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
@brief ���ø���ģ����豸����������������
@param [in] cmu_session				CMU���Ӿ��
@param [in] unit_session			����ģ�鵥Ԫ���Ӿ��
@param [in]  intranet_domain		�豸����  ��ʽ ip|port  ��1.1.1.1|9800 12U 2.5U�豸�ڲ����彻��������
@param [in]  lan_domain			    ��������  ��ʽ ip|port  ��1.1.1.1|9800 12U 2.5U 1U �豸֮�佻��������
@param [in]  public_domain		    ������  ��ʽ ip|port  ��1.1.1.1|9800	�ڹ������豸����������

@return 
@remarks    42893 add 20180824
@see UnitCommon_Set_AllIP
*/
DLIB_API void UnitCommon_Set_AllIP(t_uint32 cmu_session,t_uint32 unit_session, char* intranet_domain, char* lan_domain,char *public_domain);



/**
* @defgroup CMU_SDK����
* @{
*/

/**
* @defgroup CMU_SDKϵͳ
* @{
*/
/**
@brief CMU_SDK��ʼ��
@return 
@remarks ���������SDKһ��ʹ�ã���Ҫ���ȵ��ô˽ӿ�
@see CMU_SC_SetHeatbeat
*/
DLIB_API void CMU_SC_SetHeatbeat(t_int32 intervalTime, t_int32 outTime);

/**
@brief CMU_SDK��ʼ��
@return 
@remarks ���������SDKһ��ʹ�ã���Ҫ���ȵ��ô˽ӿ�
@see CMU_SC_Cleanup
*/
DLIB_API t_int32 CMU_SC_Init();

/**
@brief CMU_SDK��ʼ��
@return 
@remarks ���������SDKһ��ʹ�ã���Ҫ���ȵ��ô˽ӿ�
@see CMU_SC_Cleanup
*/
DLIB_API t_int32 CMU_SC_InitNoApp();

/**
@brief CMU_SDK��ʼ����������
@return 
@remarks ���������SDKһ��ʹ�ã���Ҫ���ȵ��ô˽ӿ�
@see CMU_SC_Cleanup
*/
DLIB_API t_int32 CMU_SC_InitSingle();

/**
@brief CMU_SDK����ʼ��
@return 
@remarks ���������SDKһ��ʹ�ã���Ҫ�����ô˽ӿ�
@see CMU_SC_Init
*/
DLIB_API t_int32 CMU_SC_Cleanup();

/**
@brief ������־�ļ���Ŀ¼
@param [in] dir		��־�ļ���Ŀ¼
@verbatim
ע�⣺CMU_SC_SetLogDir������־�ļ���Ŀ¼�����ֻ����ã���CMU_SC_Init֮ǰ���ã�����־�ļ������ָ��Ŀ¼��
ע���CMU_SC_SetLogCfgPath�ӿڵ�����CMU_SC_SetLogCfgPath�Ƕ�ȡһ����־�����ļ���
����ļ���������־��������𣬰���������������־��
@endverbatim
@return 
@remarks
@see
*/
DLIB_API t_int32 CMU_SC_SetLogDir(char* dir);

/**
@brief ������־�����ļ�·��
@param [in] path �����ļ�·��
@return 
@remarks
@see
*/
DLIB_API t_int32 CMU_SC_SetLogCfgPath(char* path);

/**
@brief �ͻ��˼�¼��־
@param [in] level		��־�ȼ�
@verbatim
	0	������־
	1	��Ϣ��־
	2	�ӿ���־
	3	������־
	4	������־
	5	������־
@endverbatim
@param [in] info		��־��Ϣ
@return 
@remarks
@see
*/
DLIB_API t_int32 CMU_SC_Log(t_uint32 level, char* info);

/**
@brief �ͻ��˼�¼trace
@param [in] info		trace��Ϣ
@return 
@remarks
@see
*/
DLIB_API t_int32 CMU_SC_Trace(char* info);

/**
@brief ��־���𿪹�
@param [in] level		��־�ȼ�
@verbatim
	0	������־
	1	��Ϣ��־
	2	�ӿ���־
	3	������־
	4	������־
	5	������־
@endverbatim
@param [in] flag		����
@verbatim
0	�ر�
1	����
@endverbatim
@return 
@remarks
@see
*/
DLIB_API t_int32 CMU_SC_LogEnabled(t_uint32 level, t_int32 flag);

/** @} */

/**
* @defgroup CMU_SDK�ص�����
* @{
*/

/**
@brief CMU SDK ��Ϣ�ص���������
@param [in] handle		�û���¼���
@param [in] data		��Ϣ����
@param [in] dwBufSize		���ݳ���
@param [in] pUser		�û�����
@return 
@remarks
@see CMU_SC_SetMsg
*/
typedef t_int32 (*fIbpCmuMsgCallBack)(t_uint32 handle, char *data, t_uint32 bufSize, void* pUser);

/**
@brief ����CMU SDK �ص�����
@param [in] cb		���õĻص�����
@param [in] pUser	�û�����
@return 
@remarks �ص���Ϣʾ��
@verbatim
����master��Ϣ
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="CMU" type="Request" cmd="reportMasterInfo" sequence="" session="0">
	<modulename></modulename>		ģ���� ���� DMU, VTDU
	<domid></domid>				��ID
	<ipinfo></ipinfo>			IP��Ϣ10.36.65.89|9858;
	<svrid></svrid>				����ID
	<accnum></accnum>			��������
	<adapnum></adapnum>			ת������
</root>
@endverbatim
@verbatim
�û����ߵ�
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="CMU" type="Request" cmd="logout" sequence="" session="0">
	<domid></domid>				��ID
	<userid></userid>			�û�ID
	<username></username>			�û�����
	<strdata></strdata>			�ַ�������
	<intdata></intdata>			��������
</root>
@endverbatim
@verbatim
����online��Ϣ֪ͨ
<?xml version='1.0' encoding='utf-8' ?>
<root version="1.0" unit="CMU" type="onlineNotify" cmd="onlineNotify" sequence="0" length="0">
	<server 
		servername="" 			��������
		session="" 			������
		status="" 			������״̬
	/>
</root>
@endverbatim
@verbatim
�豸��Ϣ֪ͨ��Ϣ
<?xml version='1.0' encoding='utf-8' ?>
<root version="1.0" unit="CMU" type="Notify" cmd="sharedDeviceNotify" sequence="">
	<user userid="1" username="admin"/>
	<device domid="" devcode=""  title=""/>
</root>
@endverbatim
@verbatim
�û���½��Ϣ
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="CMU" type="Notify" cmd="login" sequence="0" session="0">
<errCode>200</errCode>
</root>
@endverbatim
@see fIbpCmuMsgCallBack
*/
DLIB_API t_int32 CMU_SC_SetMsg(t_uint32 handle, fIbpCmuMsgCallBack cb, void* pUser);

/** @} */

/**
* @defgroup CMU_SDK��½�ǳ�
* @{
*/

/**
@brief �û���¼
@param [in]  timeout		��ʱʱ��
@param [in]  domainId		��ID
@param [in]  ip			����IP
@param [in]  port		����˿�
@param [in]  username		�û���
@param [in]  userpass		�û�����
@param [out] outxml		������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<handle></handle>		��½�ɹ����صľ��
	<userid></userid>		���ص��û�ID
	<domid></domid>			���ص��û���ID
	<handle></handle>		���ص��û�handle
</root>
@endverbatim
@param [in]  maxlen		��Ϣ��󳤶�
@return 200 �ɹ� ���� ʧ��
@remarks
@see CMU_SC_Logout
*/
DLIB_API t_int32 CMU_SC_Login(t_int32 timeout, char* domainId, char* ip, t_uint32 port, char *username, char *userpass, char* outxml, t_uint32 maxlen);

/**
@brief �û���¼�ӿڣ������˵�¼�û����ͣ�
@param [in]  timeout		��ʱʱ��
@param [in]  info		������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<ip>CMU��IP��ַ</ip>
	<port>CMU�Ķ˿ڣ�һ����9800</port>
	<username>��¼�û���</username>
	<userpass>��¼�û���</userpass>
	<type>��¼���ͣ�:����̨1:Web�ͻ��˲���Ա��¼2:�ֻ��ͻ��˵�¼3:PC�ͻ��˵�¼5:������ƽ̨51:Web�ͻ��˹���Ա��¼</type>
	<imei>�ֻ��ͻ��˵�¼����дimei�������ֻ��󶨹��ܣ�����д�����øù���</imei>
	<ipinfo></ipinfo>���ص�ip��ַ
</root>
@endverbatim
@param [out] outxml		������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<handle>3</handle>							��½�ɹ����صľ��
	<userid>1</userid>							���ص��û�ID
	<domid>27477</domid>						���ص��û���ID
	<groupid>123123</groupid>					�û��󶨵����
	<groupmember>615001</groupmember>			�û��󶨵���ʵ����
	<groupmemberpwd>dahua1187!</groupmemberpwd> �û��󶨺��������
	<session>19718</session>					���ص��û�session
	<errmsg/>									������Ϣ
</root>
@endverbatim
@param [in]  maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_Logout
*/
DLIB_API t_int32 CMU_SC_LoginEx(t_int32 timeout, char* info, char* outxml, t_uint32 maxlen);

/**
@brief �û��Ƿ��Ѿ���¼
@param [in] handle		��½���
@return 0 δ��¼ 1 �ѵ�¼
@remarks
@see CMU_SC_Login
*/
DLIB_API t_int32 CMU_SC_IsLogin(t_uint32 handle);

/**
@brief �û��ǳ�
@param [in] handle		��½���
@return 
@remarks
@see CMU_SC_Login
*/
DLIB_API t_int32 CMU_SC_Logout(t_uint32 handle);

/** @} */

/**
* @defgroup CMU_SDK��֯����
* @{
*/

/**
@brief ��ѯָ����֯��ϸ��Ϣ
@param [in]  handle		��½���
@param [in]  timeout		��ʱʱ��
@param [in]  domid		��֯��ID
@param [in]  orgcode		��֯����
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptOrgע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" />
</root>
@endverbatim
@param [in]  maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptOrg
*/
DLIB_API t_int32 CMU_SC_QueryOrg(t_uint32 handle, t_int32 timeout, char* domid, char* orgcode, char*outxml, t_uint32 maxlen);

/**
@brief ��ѯ������֯
@param [in]  handle		��½���
@param [in]  timeout		��ʱʱ��
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptOrgע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" >
		<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" >
			<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" />
		</org>
	</org>
</root>
@endverbatim
@param [in]  maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptOrg
*/
DLIB_API t_int32 CMU_SC_QueryAllOrg(t_uint32 handle, t_int32 timeout, char*outxml, t_uint32 maxlen);

/**
@brief ��ѯ������֯(����Ȩ�޹���)
@param [in]  handle		��½���
@param [in]  timeout		��ʱʱ��
@param [in]	 info				������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<funid></funid>
</root>
@endverbatim
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptOrgע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" >
		<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" >
			<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" />
		</org>
	</org>
</root>
@endverbatim
@param [in]  maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptOrg
*/
DLIB_API t_int32 CMU_SC_QueryAllOrgEx(t_uint32 handle, t_int32 timeout, char *info, char*outxml, t_uint32 maxlen);

/**
@brief ����������ѯ������֯
@param [in]  handle		��½���
@param [in]  timeout		��ʱʱ��
@param [in] info		������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<orgdomid></orgdomid>��:ȫ��
	<orgcode></orgcode>��:ȫ��
	<orgtype></orgtype>-1:ȫ�� 1:��֯ 2:���� 3:���ţ����������ö���(",")�ָ�
</root>
@endverbatim
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptOrgע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" orgtype=""/>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" orgtype=""/>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" orgtype=""/>
</root>
@endverbatim
@param [in]  maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptOrg
*/
DLIB_API t_int32 CMU_SC_QueryOrgEx(t_uint32 handle, t_int32 timeout, char *info, char*outxml, t_uint32 maxlen);

/**
@brief ��ѯ����֯
@param [in]  handle		��½���
@param [in]  timeout		��ʱʱ��
@param [in]  domid		��ID
@param [in]  parentorgcode	����֯����(Ϊ���ַ������ظ���֯��Ϣ)
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptOrgע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" />
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" />
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" />
</root>
@endverbatim
@param [in]  maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptOrg
*/
DLIB_API t_int32 CMU_SC_QuerySubOrg(t_uint32 handle, t_int32 timeout, char* domid, char* parentorgcode, char*outxml, t_uint32 maxlen);

/**
@brief ��ѯ����֯
@param [in]  handle		��½���
@param [in]  timeout		��ʱʱ��
@param [in]  domid		��ID
@param [in]  parentorgcode	����֯����(Ϊ���ַ������ظ���֯��Ϣ)
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptOrgע��)
@verbatim
�� CMU_SC_QuerySubOrg
@endverbatim
@param [in]  maxlen		��Ϣ��󳤶�
@return 
@remarks ������CMU_SC_QuerySubOrg�����ڵ�ǰ�û������һ����֯������Բ������豸Ϊ0�����˵������֯
@see CMU_SC_OptOrg
*/
DLIB_API t_int32 CMU_SC_QuerySubOrg_FilterEmpty(t_uint32 handle, t_int32 timeout, char* domid, char* parentorgcode, char*outxml, t_uint32 maxlen);

/**
@brief ��ѯ����֯����Ҫ�ͷŷ��ض����ڴ棩
@param [in]  handle		��½���
@param [in]  timeout		��ʱʱ��
@param [in]  domid		��ID
@param [in]  parentorgcode	����֯����(Ϊ���ַ������ظ���֯��Ϣ)
@param [out] errorcode		������
@param [out]  reallen		��Ϣʵ�ʳ���
@return 
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" />
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" />
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" />
</root>
@endverbatim
@remarks ���ͷŷ��ض����ڴ棡���ͷŷ��ض����ڴ棡���ͷŷ��ض����ڴ棡
@see CMU_SC_OptOrg
*/
DLIB_API char* CMU_SC_QuerySubOrgXXXX(t_uint32 handle, t_int32 timeout, char* domid, char* parentorgcode, t_int32 *errorcode, t_uint32 *reallen);

/**
@brief ��ѯ�Զ������
@param [in]	session			��½���
@param [in]	timeout			��ʱʱ��
@param [in]	 info				������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<!--userid��parentid��id�����ֶ�ͬʱֻ����һ�������������ֶ���-1-->
	<userid>���������û�id</userid>
	<parentid>���鸸�ڵ�id</parentid>
	<id>����id</id>
	<issuborg>0</issuborg> �Ƿ�Ҫ��ѯ�ӽڵ�  1��ѯ, 0����ѯ, û���ֶ�ʱ��ѯ  ֻ�ڰ�userid��ѯʱ��Ч
	<type></type> //���Ӳ�ѯ����,Ĭ�ϲ����ѯ2����̨���� ,����ֵ���ѯָ������,3 ��ѯ��Ƶ�豸����
	<size>ÿҳ���ؼ�¼������</size>
	<curpage>�ڼ�ҳ����0��ʼ</curpage>
</root>
@endverbatim
@param [out] outxml				������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total></total>
	<group id="����id"
		parentid="���鸸�ڵ�ID"
		name="�������ƣ�64�ֽڣ���ӡ��޸���Ч"
		type="�������ͣ�ͨѶ¼����:1"
	>
		<group id="" parentid="" name="" type="">
			<group id="" parentid="" name="" type=""/>
		</group>
	</group>
</root>
@endverbatim
@param [in]  maxlen				��Ϣ��󳤶�
@return 
@remarks δ����Ĳ鲻��
@see 
*/
DLIB_API t_int32 CMU_SC_QueryGroup(t_uint32 session, t_int32 timeout, char *info, char *outxml, t_uint32 maxlen);

/**
@brief ��ѯ�Զ����������Ķ���
@param [in]	session			��½���
@param [in]	timeout			��ʱʱ��
@param [in]	 info				������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<groupid></groupid>
	<funcid></funcid>��Ҫ�����豸��Ȩ������
	<size>ÿҳ���ؼ�¼������</size>
	<curpage>�ڼ�ҳ����0��ʼ</curpage>
</root>
@endverbatim
@param [out] outxml				������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total></total>
	<group id="����id"
		parentid="���鸸�ڵ�ID"
		name="�������ƣ�64�ֽڣ���ӡ��޸���Ч"
		type="�������ͣ�ͨѶ¼����:1"
	>
		<device devid="3844" domid="73807" devcode="88888channel1" devtype="31" manufid="1" title="通道1" status="2" orgdomid="73807" orgcode="1" devpath="0-3772-" orgpath="0-1-522" devlinktype="0" updatetime="2016-09-01 20:16:56"/>
		<user id="3" userid="3" name="fz" domid="66404">
			<phone number="">
			<phone number="">
		</user>
		<contact domid="66404" id="4" userid="1" name="001">
			<telephone id="4" number="22005" desc=""/>
		</contact>
	</group>
</root>
@endverbatim
@param [in]  maxlen				��Ϣ��󳤶�
@return 
@remarks δ����Ĳ鲻��
@see 
*/
DLIB_API t_int32 CMU_SC_QueryGroupObject(t_uint32 session, t_int32 timeout, char *info, char *outxml, t_uint32 maxlen);

/**
@brief ��ѯ����֯
@param [in]  handle		��½���
@param [in]  timeout		��ʱʱ��
@param [in] info		������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<funid></funid>
	<domid></domid>
	<parentorgdomid></parentorgdomid>
	<parentorgcode></parentorgcode>
	<orgtype></orgtype>-1:ȫ�� 1:��֯ 2:���� 3:���ţ����������ö���(",")�ָ�
</root>
@endverbatim
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptOrgע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" orgtype=""/>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" orgtype=""/>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" orgtype=""/>
</root>
@endverbatim
@param [in]  maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptOrg
*/
DLIB_API t_int32 CMU_SC_QuerySubOrgEx(t_uint32 handle, t_int32 timeout, char *info, char*outxml, t_uint32 maxlen);

/** @} */

/**
* @defgroup CMU_SDK�豸����
* @{
*/

/**
@brief ͨ����֯��ѯ�豸��Ҫ��Ϣ
@param [in]  handle		��½���
@param [in]  timeout		��ʱʱ��
@param [in]  domid		��֯��ID
@param [in]  orgcode		��֯����
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptDeviceע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode=""  orgpath="" title="" updatetime="" desc="" >
		<device devid="2324" domid="30824" devcode="IMDS_1000" olddomid="" olddevcode="" 
			parentdevid="0" parentdomid="" parentdevcode="" orgid="1" orgdomid="30824" 
			orgcode="1" devpath="0-" orgpath="0-1" devtype="26" manufid="1" title="test_1000" 
			status="1" devposidx="0" updatetime="2017-03-04 11:23:22" devlinktype="0" 
			extend='&lt;extension deviceType="26" extensionName="test_1000" extensionNumber="1000" extensionPassword="dahua1187!" alternateNumber="" extensionLevel="1" interposeLevel="0" transferNumber="" callTransfer="0" dialPlan="255" DTMFMode="0" recordMode="1" chargeMode="0" advancePayment="1" callHold="0" dnd="0" limitOutIn="0" extensionType="3" /&gt;' 
			relatedomid="" relatedevcode="" relatedevtitle="" loginname="" loginpwd="" ipaddr="" 
			portdev="0" streamtype="0" contrator="" locationid="0" installspot="" installtime="0000-00-00 00:00:00" 
			maintainer="" phone="" model="" visible="0" longitude="0" latitude="0" desc="" orgname="test"/>
			//��ѡ����Ϣ
			<item domid="" devcode="" slavedomid="" slavedevcode="" />
			<item domid="" devcode="" slavedomid="" slavedevcode="" />
		</device>
	</org>
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDevice(t_uint32 handle, t_int32 timeout, char* domid, char* orgcode, char*outxml, t_uint32 maxlen);

/**
@brief ͨ����֯��ѯ�豸��Ϣ(�����豸����)
@param [in]  handle		��½���
@param [in]  timeout		��ʱʱ��
@param [in]  domid			��֯��ID
@param [in]  orgcode		��֯����
@param [in]  devtype		�豸����(""ȫ��, ��������ö��ŷָ�����"1,2,3")
@param [out] outxml			��ѯ��Ϣ(���CMU_SC_OptDeviceע��)
@verbatim
//��������豸���;���������Ϣ����Ҫ��Ϣ���£�
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode=""  orgpath="" title="" updatetime="" desc="" >
		<device domid="" devcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" devlinktype="" display="" updatetime="" />
	</org>
</root>
//һ���豸
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode=""  orgpath="" title="" updatetime="" desc="" >
		<device domid="" devcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" devlinktype="" detecttype="" detectpart="" targettype="" typedesc="" ratedcurrent="" heatfeature="" faultdesc="" sequence="" time="" installspot="" installtime="" maintainer="" model="" visible="" desc="" />
		<device domid="" devcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" devlinktype="" detecttype="" detectpart="" targettype="" typedesc="" ratedcurrent="" heatfeature="" faultdesc="" sequence="" time="" installspot="" installtime="" maintainer="" model="" visible="" desc="" />
	</org>
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDeviceEx(t_uint32 handle, t_int32 timeout, char* domid, char* orgcode, char *devtype, char*outxml, t_uint32 maxlen);

/**
@brief ͨ����֯�͹���Ȩ�޲�ѯ�豸��Ҫ��Ϣ
@param [in]  handle		��½���
@param [in]  timeout		��ʱʱ��
@param [in]  domid		��֯��ID
@param [in]  orgcode		��֯����
@param [in]  funcid			����Ȩ��ID
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptDeviceע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode=""  orgpath="" title="" updatetime="" desc="" >
		<device domid="" devcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" />
	</org>
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDeviceByFuncId(t_uint32 handle, t_int32 timeout, char* domid, char* orgcode, t_int32 funcid, char*outxml, t_uint32 maxlen);

/**
@brief ͨ����֯�͹���Ȩ�޲�ѯ�豸��Ҫ��Ϣ(�����豸����)
@param [in]  handle		��½���
@param [in]  timeout		��ʱʱ��
@param [in]  domid		��֯��ID
@param [in]  orgcode		��֯����
@param [in]  devtype		�豸����(""ȫ��, ��������ö��ŷָ�����"1,2,3")
@param [in]  funcid			����Ȩ��ID
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptDeviceע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode=""  orgpath="" title="" updatetime="" desc="" >
		<device domid="" devcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" />
	</org>
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDeviceByFuncIdEx(t_uint32 handle, t_int32 timeout, char* domid, char* orgcode, char* devtype, t_int32 funcid, char*outxml, t_uint32 maxlen);

/**
@brief �����豸��ѯ�豸��ϸ��Ϣ
@param [in]  handle		��½���
@param [in]	 timeout	��ʱʱ��
@param [in]	 domid		�豸��ID
@param [in]	 devcode	�豸����
@param [in]	 devtype	�豸����(δ֪������0)
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptDeviceע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<device domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" display="" devlinktype="" updatetime="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" >
		<channel domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" chnidx="" accesory="" lighttype="" guardtype="">
			//��ѡ����Ϣ
			<item domid="" devcode="" slavedomid="" slavedevcode="" />
			<item domid="" devcode="" slavedomid="" slavedevcode="" />
		</channel>
		//��ѡ����Ϣ
		<item domid="" devcode="" slavedomid="" slavedevcode="" />
		<item domid="" devcode="" slavedomid="" slavedevcode="" />
	</device>
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDevDetail(t_uint32 handle, t_int32 timeout, char* domid, char* devcode, t_int32 devtype, char*outxml, t_uint32 maxlen);

/**
@brief �����豸�͹���Ȩ�޲�ѯ�豸��ϸ��Ϣ
@param [in]  handle		��½���
@param [in]	 timeout	��ʱʱ��
@param [in]	 domid		�豸��ID
@param [in]	 devcode	�豸����
@param [in]	 devtype	�豸����(δ֪������0)
@param [in]  funcid			����Ȩ��ID
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptDeviceע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<device domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" >
		<channel domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" chnidx="" accesory="" />
	</device>
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDevDetailByFuncId(t_uint32 handle, t_int32 timeout, char* domid, char* devcode, t_int32 devtype, t_int32 funcid, char* outxml, t_uint32 maxlen);

/**
@brief ����ͨ����ѯ�豸��ϸ��Ϣ
@param [in]  handle		��½���
@param [in]	 timeout	��ʱʱ��
@param [in]	 domid		ͨ����ID
@param [in]	 chncode	ͨ������
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptDeviceע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<device domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" >
		<channel domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" chnidx="" accesory="" />
	</device>
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDevByChn(t_uint32 handle, t_int32 timeout, char* domid, char* chncode, char* outxml, t_uint32 maxlen);

/**
@brief ͨ����֯��ѯ�豸�б���ϸ��Ϣ(��ҳ)
@param [in]  handle		��½���
@param [in]  timeout		��ʱʱ��
@param [in]  domid			��֯��ID
@param [in]  code			��֯����
@param [in]	 size			ҳ��С
@param [in]	 curpage		��ǰҳ(��0��ʼ)
@param [out] outxml			��ѯ��Ϣ(���CMU_SC_OptDeviceע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total></total>			������
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDevDetailByCode(t_uint32 handle, t_int32 timeout, char* domid, char* code, t_int32 size, t_int32 curpage, char* outxml, t_uint32 maxlen);

/**
@brief ͨ����֯���豸���Ͳ�ѯ�豸�б���ϸ��Ϣ(��ҳ)
@param [in]  handle		��½���
@param [in]  timeout		��ʱʱ��
@param [in]  domid			��֯��ID
@param [in]  code			��֯����
@param [in]  devtype		�豸����(""ȫ��, ��������ö��ŷָ�����"1,2,3")
@param [in]	 size			ҳ��С
@param [in]	 curpage		��ǰҳ(��0��ʼ)
@param [out] outxml			��ѯ��Ϣ(���CMU_SC_OptDeviceע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total></total>			������
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDevDetailByCodeEx(t_uint32 handle, t_int32 timeout, char* domid, char* code, char *devtype, t_int32 size, t_int32 curpage, char* outxml, t_uint32 maxlen);

/**
@brief ����������ѯ�豸��Ҫ����ϸ����Ϣ
@param [in]  handle		��½���
@param [in]  timeout		��ʱʱ��
@param [in]  domid			��֯��ID��""ȫ����
@param [in]  code			��֯���루""ȫ����
@param [in]	 devname		�豸���ƣ�""ȫ����
@param [in]	 devtype		�豸����(0ȫ��)
@param [in]	 manuftype		��������(-1ȫ��)
@param [in]	 status			����״̬(0ȫ�� 1 ���� 2 ������)
@param [in]	 size			ҳ��С
@param [in]	 curpage		��ǰҳ(��0��ʼ)
@param [out] outxml			��ѯ��Ϣ(���CMU_SC_OptDeviceע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total></total>			������
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDevBrief(t_uint32 handle, t_int32 timeout, char* domid, char* code, char *devname, t_int32 devtype, t_int32 manuftype, t_int32 status, t_int32 size, t_int32 curpage, char* outxml, t_uint32 maxlen);

/**
@brief ����������ѯ�豸��Ҫ����ϸ����Ϣ
@param [in]  handle		��½���
@param [in]  timeout		��ʱʱ��
@param [in]  info			������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<domid />				��֯��ID��""ȫ����
	<code />				��֯���루""ȫ����
	<devname />				�豸���ƣ�""ȫ����
	<devtype />				�豸����(""ȫ��, ��������ö��ŷָ�����"1,2,3")
	<manuftype />			��������(-1ȫ��)
	<status />				����״̬(0ȫ�� 1 ���� 2 ������)
	<size />				ҳ��С
	<curpage />				��ǰҳ(��0��ʼ)
	<isSubOrg />			�Ƿ��ѯ�ӽڵ�1�� 0����
</root>
@endverbatim		
@param [out] outxml			��ѯ��Ϣ(���CMU_SC_OptDeviceע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total></total>			������
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDevBriefEx(t_uint32 handle, t_int32 timeout, char *info, char* outxml, t_uint32 maxlen);

/**
@brief ���ݺ����ѯ������Ҫ����ϸ����Ϣ
@param [in]  handle		��½���
@param [in]  timeout		��ʱʱ��
@param [in]  info			������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<domid />				��֯��ID��""ȫ����
	<code />				��֯���루""ȫ����
	<number />				�������루""ȫ����
	<devname />				�������ƣ�""ȫ����
	<devtype />				�豸����(""ȫ��, ��������ö��ŷָ�����"1,2,3")
	<size />				ҳ��С
	<curpage />				��ǰҳ(��0��ʼ)
	<isSubOrg />			�Ƿ��ѯ�ӽڵ�1�� 0����
</root>
@endverbatim		
@param [out] outxml			��ѯ��Ϣ(���CMU_SC_OptDeviceע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total></total>			������
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryPhoneDevBriefEx(t_uint32 handle, t_int32 timeout, char *info, char* outxml, t_uint32 maxlen);
/** @} */

/**
* @defgroup CMU_SDK�û���ɫ����
* @{
*/

/**
@brief ��ѯ�������û���Ϣ
@param [in]  handle		��½���
@param [in]	 timeout	��ʱʱ��
@param [in]	 userid		�û�ID
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptUserע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<user userid="" usertype="" treeid="" username="" creatorid="" loginname="" loginpwd="" telephone="" status="" ip="" updatetime="" begindate="" enddate="" lockstatus="" orgdomid="" orgcode=""  medianum="" email="" multi="" flag="" extradata="" imei=""/>
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptUser
*/
DLIB_API t_int32 CMU_SC_QueryUser(t_uint32 handle, t_int32 timeout, t_int32 userid, char*outxml, t_uint32 maxlen);

/**
@brief ��ѯ�������û���Ϣ��չ�ӿ�
@param [in]  handle		��½���
@param [in]	 timeout	��ʱʱ��
@param [in]	 inxml		������Ϣ
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<infotype/>		//Ҫ��ѯ������
	<user userid="" domainid="" orgdomid="" loginfrom=""/>
</root>
@param [out] outxml		�����Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<errcode/>
	<errmsg/>
	<user userid="" usertype="" treeid="" username="" creatorid="" loginname="" loginpwd="" telephone="" status="" ip="" updatetime="" begindate="" enddate="" lockstatus="" orgdomid="" orgcode=""  medianum="" email="" multi="" flag="" extradata="" imei=""/>
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
*/
DLIB_API t_int32 CMU_SC_QueryUserInfoEx(t_uint32 handle, t_int32 timeout, char* inxml, char* outxml, t_uint32 maxlen);

/**
@brief �����ѯ�û���Ϣ
@param [in]  handle		��½���
@param [in]	 timeout	��ʱʱ��
@param [in]	 domid		�����
@param [in]	 userid		�û�ID
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptUserע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<user userid="" usertype="" treeid="" username="" creatorid="" loginname="" loginpwd="" telephone="" status="" ip="" updatetime="" begindate="" enddate="" lockstatus="" orgdomid="" orgcode=""  medianum="" email="" multi="" flag="" extradata=""	/>
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptUser
*/
DLIB_API t_int32 CMU_SC_QueryDomUser(t_uint32 handle, t_int32 timeout, char *domid, t_int32 userid, char*outxml, t_uint32 maxlen);

/**
@brief ��ѯ��֯���û�
@param [in]  handle		��½���
@param [in]	 timeout	��ʱʱ��
@param [in]	 domid		��֯��ID
@param [in]	 orgcode	��֯����
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptUserע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<user userid="" usertype="" treeid="" username="" creatorid="" loginname="" loginpwd="" telephone="" status="" ip="" updatetime="" begindate="" enddate="" lockstatus="" orgdomid="" orgcode=""  medianum="" email="" multi="" flag="" extradata="" imei=""/>
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptUser
*/
DLIB_API t_int32 CMU_SC_QueryUserByOrg(t_uint32 handle, t_int32 timeout, char* domid, char* orgcode, char*outxml, t_uint32 maxlen);

/**
@brief ��ѯ�û���Ϣ��չ�ӿ�
@param [in]  handle		��½���
@param [in]	 timeout	��ʱʱ��
@param [in]	 info		������Ϣ
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<orgcode></orgcode>		��ѯ����֯�ṹid(����)
	<domid></domid>			��ѯ����֯�ṹ��id(����)
	<username></username>	��ѯ���û���(ѡ��)
	<funcid></funcid>		����id(���ڲ�����Ȩ��)
	<size></size>			��ҳ��(����)
	<curpage></curpage>		��ǰ��ʾҳ(����)
</root>
@endverbatim
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptUserע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<user userid="" usertype="" treeid="" username="" creatorid="" loginname="" loginpwd="" telephone="" status="" ip="" updatetime="" begindate="" enddate="" lockstatus="" orgdomid="" orgcode=""  medianum="" email="" multi="" flag="" extradata="" imei=""/>
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_QueryUserEx
*/
DLIB_API t_int32 CMU_SC_QueryUserEx(t_uint32 handle, t_int32 timeout,char* inxml,char* outxml, t_uint32 maxlen);

/**
@brief ֻ��ѯ��ǰ��֯���û�
@param [in]  handle		��½���
@param [in]	 timeout	��ʱʱ��
@param [in]	 domid		��֯��ID
@param [in]	 orgcode	��֯����
@param [in]	 funcid	
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptUserע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<user userid="" usertype="" treeid="" username="" creatorid="" loginname="" loginpwd="" telephone="" status="" ip="" updatetime="" begindate="" enddate="" lockstatus="" orgdomid="" orgcode=""  medianum="" email="" multi="" flag="" extradata="" imei=""/>
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptUser
*/
DLIB_API t_int32 CMU_SC_QueryUserByThisOrg(t_uint32 handle, t_int32 timeout, char* domid, char* orgcode, int funcid, char*outxml, t_uint32 maxlen);

/**
@brief ��ѯ�����û�
@param [in]  handle		��½���
@param [in]	 timeout	��ʱʱ��
@param [out] outxml		��ѯ��Ϣ(���CMU_SC_OptUserע��)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<user domid="" userid="" usertype="" treeid="" username="" creatorid="" loginname="" loginpwd="" telephone="" status="" ip="" updatetime="" begindate="" enddate="" lockstatus="" orgdomid="" orgcode=""  medianum="" email="" multi="" flag="" extradata="" />
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
@see CMU_SC_OptUser
*/
DLIB_API t_int32 CMU_SC_QueryAllUser(t_uint32 handle, t_int32 timeout, char*outxml, t_uint32 maxlen);

/**
@brief ��ѯ��ǰ�����û�
@param [in]  handle	��½���
@param [in]	 timeout	��ʱʱ��
@param [out] outxml		��ѯ��Ϣ
@verbatim
<root>
	<user userid="1" username="admin" loginname="admin" status="1" domid="65008">
		<device domid="65008" devcode="MCU_936805" devtype="20001" streamtype="0" sessionid="111" loginfrom="1" virtualnumber="ppppp" extension='&lt;extension deviceType="20001" extensionName="ext_936805" extensionNumber="936805" extensionPassword="dahua1187!" alternateNumber="" extensionLevel="2" interposeLevel="0" transferNumber="" callTransfer="0" dialPlan="255" DTMFMode="1" recordMode="0" chargeMode="1" advancePayment="1" callHold="1" dnd="0" limitOutIn="0" extensionType="1" /&gt;'/>
	</user>
	<user userid="2" username="rpu" loginname="rpu" status="1" domid="65008"/>
	<user userid="3" username="invisibleadmin" loginname="2de25ec97b45ea2f74bf91799bcadc80" status="1" domid="65008"/>
	<user userid="7" username="niu102" loginname="niu104" status="1" domid="65008"/>
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks
*/
DLIB_API t_int32 CMU_SC_QueryOnlineUser(t_uint32 handle, t_int32 timeout, char*outxml, t_uint32 maxlen);


/**
@brief �鵱ǰ�����û�����չ�ӿ�
@param [in]  handle	��½���
@param [in]	 timeout	��ʱʱ��
@param [in]	 imxml		������Ϣ
@verbatim
<root>
	<user userid="1" />
	<user userid="2" />
	<user userid="3" />
	<user userid="7" />
</root>
@endverbatim
@param [out] outxml		��ѯ��Ϣ
@verbatim
<root>
	<user userid="1" username="admin" loginname="admin" status="1" domid="65008">
		<device domid="65008" devcode="MCU_936805" devtype="20001" streamtype="0" sessionid="111" loginfrom="1" virtualnumber="ppppp" extension='&lt;extension deviceType="20001" extensionName="ext_936805" extensionNumber="936805" extensionPassword="dahua1187!" alternateNumber="" extensionLevel="2" interposeLevel="0" transferNumber="" callTransfer="0" dialPlan="255" DTMFMode="1" recordMode="0" chargeMode="1" advancePayment="1" callHold="1" dnd="0" limitOutIn="0" extensionType="1" /&gt;'/>
	</user>
	<user userid="2" username="rpu" loginname="rpu" status="1" domid="65008"/>
	<user userid="3" username="invisibleadmin" loginname="2de25ec97b45ea2f74bf91799bcadc80" status="1" domid="65008"/>
	<user userid="7" username="niu102" loginname="niu104" status="1" domid="65008"/>
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks CMU_SC_QueryOnlineUser�ǲ�ѯ���е������û���
	CMU_SC_QueryOnlineUser_Ex����չ�ӿڣ�����ӿڰ����û����󣬲�ѯָ�����û����൱������⣬inxmlΪ""��ʾ��ѯ���С�
*/
DLIB_API t_int32 CMU_SC_QueryOnlineUser_Ex(t_uint32 handle, t_int32 timeout, char* inxml, char* outxml, t_uint32 maxlen);



/**
@brief ��ѯ��ǰ�����û���Id
@param [in]  handle	��½���
@param [in]	 timeout	��ʱʱ��
@param [in]	 imxml		������Ϣ
@verbatim
<root>
	<isDetail></isDetail>	�Ƿ���Ҫ�û���ϸ��Ϣ 1 ��ѯ��ϸ��Ϣ
	<orgcode></orgcode>		��ѯ����֯�ṹid
	<domid></domid>			��ѯ����֯�ṹ��id
	<number></number>		��ѯ���û�����
	<username></username>	��ѯ���û���
	<status></status>		��ѯ���û��Ƿ����� -1 ȫ�� 0 ������ 1����
	<funcid></funcid>		����id
	<order></order>			����ʽ 1 ���û���ƴ������(Ӣ����ǰ�����ں�)
	<size></size>			��ҳ��(����)
	<curpage></curpage>		��ǰ��ʾҳ(����)
</root>
@endverbatim
@param [out] outxml		��ѯ��Ϣ
@verbatim
<root>
	<user userid="1" />
	<user userid="2" />
	<user userid="3" />
	<user userid="7" />
</root>
@endverbatim
@param [in]	 maxlen		��Ϣ��󳤶�
@return 
@remarks CMU_SC_QueryOnlineUser���������û��Լ��󶨵���Ϣ��CMU_SC_QueryOnlineUser_Id�������������û���ID
*/
DLIB_API t_int32 CMU_SC_QueryOnlineUser_Id(t_uint32 handle, t_int32 timeout,char* inxml, char* outxml, t_uint32 maxlen);

/** @} */

#ifdef __cplusplus
}
#endif

#endif



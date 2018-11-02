/**
 * Copyright (c) 2014~2015, �㽭��ϵͳ�������޹�˾ All rights reserved.
 * \file		ibp_error_enum.h
 * \brief		ibp_error_enum
 * \author		24997
 * \date		2016��6��28��
 * \note		eIBP_Err��������Ϣ
 */
#ifndef _IBP_ERROR_ENUM_H_
#define _IBP_ERROR_ENUM_H_

/**
* @defgroup ������
* @{
*/

/**
@brief ��������Ϣ
@remarks
@see
*/
typedef enum {
	IBP_Err_OK = 200,										///<��ȷ������
	
	IBP_Err_Common_Begin = 300,								///<ͨ�ô����뿪ʼ
	IBP_Err_Common_XML_NULL,								///<xmlΪ��
	IBP_Err_Common_XML_ERR,									///<xml�쳣
	IBP_Err_Common_No_Buffers,								///<���治��
	IBP_Err_Common_SendMsg_Failed,							///<��Ϣ����ʧ��
	IBP_Err_Common_PARAM_ERR,								///<��������
	IBP_Err_Common_Device_Offline,							///<�豸����
	IBP_Err_Common_IpPort_Dup,								///<dvr�豸��IP,port�ظ�
	IBP_Err_Common_NETSDK,									///<netsdk����
	IBP_Err_NO_RIGHTS,										///<û�в���Ȩ��
	IBP_Err_CANNOT_FIND_DEVICE,								///<û���ҵ�������豸
	IBP_Err_CANNOT_FIND_USER,								///<��SessionIdû���ҵ�UserId
	IBP_Err_Common_IbpProtocol_NULL,						///<Э��Ϊ��
	IBP_Err_Common_Socket_Err,								///<socket�����쳣
	IBP_Err_SerialPort_InUse,								///<���п����ڱ�ʹ��
	IBP_Err_SerialPort_OpenFailed,							///<���ڴ�ʧ��

	IBP_Err_CANNOT_SUPPORT_DVR_TYPE,					    ///<��֧�ֵ�DVR����

	
	IBP_Err_DB_Begin = 400,									///<���ݿ�����뿪ʼ
	IBP_Err_DBConnect_Fail = 400,							///<���ݿ�Ĵ��������һ�����Ӵ���
	IBP_Err_DBOperate_Fail,									///<���ݿ���ɾ�Ĵ���
	IBP_Err_DBQuery_Fail,									///<���ݿ��ѯ����
	IBP_Err_DBInsert_Fail,									///<���ݿ�insert����
	IBP_Err_DBDelete_Fail,									///<���ݿ�delete����
	IBP_Err_DBSelect_Fail,									///<���ݿ�select����
	IBP_Err_DBUpdate_Fail,									///<���ݿ�update����
	IBP_Err_DBOperate_Fail_RecordNotExists,					///<���ݿ�����ļ�¼������
	IBP_Err_DB_End = 499,									///<���ݿ���������
	
	IBP_ERR_COMMON_OUTPROCESS_Begin = 900,					///<�ؼ�������ֿ�����ʼ
	IBP_ERR_COMMON_OUTPROCESS_NO_SESSION = 900,				///<outprocess�Ҳ������
	IBP_ERR_COMMON_OUTPROCESS_SERVICE_UNAVAILABLE,			///<outprocess���񲻿���
	IBP_ERR_COMMON_OUTPROCESS_NOT_FOUND_BYSEQ,				///<û���ҵ�peer
	IBP_ERR_COMMON_OUTPROCESS_PROTOCOL_NULL,				///<Э��Ϊ��
	IBP_ERR_COMMON_OUTPROCESS_End = 909,					///<�ؼ�������ֿ��������
	
	IBP_ERR_COMMON_LOADBALANCE_CMU_ALEADY_LOGIN = 910,		///<���ؾ���CMU�Ѿ���¼
	IBP_ERR_COMMON_LOADBALANCE_NOT_MASTER,					///<���ؾ�����master
	IBP_Err_Common_End = 999,								///<ͨ�ô������
	
	IBP_Err_CMU_Begin = 1000,								///<CMU��ʼ
	IBP_Err_Nothing_Found,									///<δ�ҵ�
	IBP_Err_KEY_CONFLICT,									///<�ؼ��ֳ�ͻ
	IBP_Err_USERNAME_CONFLICT,								///<�û�����ͻ
	IBP_Err_USER_NOT_LOGON,									///<�û�δ��¼
	IBP_Err_USERNAME_NONEXISTENT,							///<�û���������
	IBP_Err_ERROR_PASSWORD,									///<�������
	IBP_Err_USER_LOCKED,									///<�û�����
	IBP_Err_USER_OUT_OF_DATE,								///<�û�����
	IBP_Err_USER_NOT_IN_DATE,								///<�û�����ʹ������
	IBP_Err_USER_MULT_LOGIN,								///<�û��ظ���¼
	IBP_Err_USER_ADMIN_ONLINE_OVER,							///<admin���߳�������
	IBP_Err_USER_USER_ONLINE_OVER,							///<�û����߳�������
	IBP_Err_USER_MAX,										///<�û��ﵽ���ֵ	
	IBP_Err_EXT_PASSWORD_ERR,								///<�������벻��Ϊ��
	IBP_Err_EXT_NUMBER_DUPLICATE,							///<�������������к���򱸺��ظ�
	IBP_Err_EXT_ATTENDANT_DUPLICATE,						///<�����������ܻ������ظ�
	IBP_Err_EXT_EMPTY_ERR,									///<�ֻ�����Ϊ��
	IBP_Err_ORG_DEL_HAVSUBORG,								///<������֯������ɾ������֯
	IBP_Err_ORG_DEL_HAVSUBDEV,								///<�����豸������ɾ������֯
	IBP_Err_ORG_DEL_HAVUSER,								///<�����û�������ɾ������֯
	IBP_Err_ORG_DEL_HAVDOMAIN,								///<�����򣬲���ɾ������֯
	IBP_Err_DOMAIN_ID_ERR,									///<DomainId ����
	IBP_Err_CMU_ORG_NOT_EXIST,								///<��֯������
	IBP_Err_CMU_SAME_CODE_DEV_NOT_EXIST,					///<�����ڸñ����豸
	IBP_Err_CMU_SAME_CODE_DEV_EXIST,						///<�Ѵ��ڸñ����豸
	IBP_Err_CMU_OLD_DEV_NOT_EXIST,							///<ԭ�豸������
	IBP_Err_CMU_PARENT_DEV_NOT_EXIST,						///<���豸������
	IBP_Err_CMU_Not_Match_Database,							///<Cmu�����ݿ�汾��ƥ��
	IBP_Err_ORG_DEL_HAVROLE,								///<���н�ɫ������ɾ������֯
	IBP_Err_USER_BIND_OTHER_DEVICE,							///<�û����������豸
	IBP_Err_ERROR_PASSWORD_FOR_5,							///<�������5�Σ�24Сʱ�Ժ�����
	IBP_Err_USER_MULT_LOGIN_FROM,							///<�ն��ظ���¼
	IBP_Err_USER_MULT_LOGIN_NUMBER,							///<�ն˰󶨵ĺ����ظ���¼
	IBP_Err_CONTACT_NUM_DUPLICATE,							///<ͨѶ¼�����ظ�
	IBP_Err_BIND_GROUP_NUM_DUPLICATE,						///<�󶨵�������ظ�
	IBP_Err_BIND_GROUP_NUM_NOT_ENOUGH,						///<�󶨵�����벻����
	IBP_Err_ARSSERVER_OFFLINE,								///<ars��������
	IBP_Err_NOT_CONNECT_FROM_UAC,							///<APP��Ҫ��UAC�������ӵ�½
	IBP_Err_VERSION_ID_DUPLICATE,							///<�汾���ظ�
	IBP_Err_EXT_GATEWAY_DUPLICATE,							///<�������������غ����ظ�
	IBP_Err_LDAP_AUTHENTICATION_ERR,						///<ldap��Ȩʧ��
	IBP_Err_LDAP_USER_NOT_IN_DOMAIN,						///<�û����ڵ�ǰ����
	IBP_Err_PARTIAL_SUCCESS,								///<���ֲ����ɹ�
	IBP_Err_BIND_NUM_DUPLICATE,								///<�����ظ���
	IBP_ERR_IEMI_ERR,										///<IEMIֵΪ0,��ʼ��
	IBP_Err_CMU_End = 1099,									///<CMU����
	
	IBP_Err_VTDU_Begin = 1100,								///<VTDU����
	IBP_Err_Start_Unfinished,								///<VTDU����δ���
	IBP_Err_Not_Find_VRU,									///<δ����vru
	IBP_Err_No_Enough_Capability,							///<û���㹻������
	IBP_Err_Device_Not_Support,								///<�豸��֧��
	IBP_Err_Cannot_Find_Device,								///<���Ҳ����豸
	IBP_Err_Not_Find_Slave,									///<�Ҳ���slave
	IBP_Err_SendMsg_MasterToSlave,							///<master��slave������Ϣʧ��
	IBP_Err_SendMsg_MasterToDomain,							///<master������������Ϣʧ��
	IBP_Err_Device_Offline,									///<�豸����
	IBP_Err_DllName_Empty,									///<dll��Ϊ��
	IBP_Err_Record_Seek_Format,								///<¼���϶���ʽ����
	IBP_Err_Cascade_Server_Offline,							///<��������rtsp���ӵ���
	IBP_Err_Channel_Used_In_Talking,						///<�����Խ�-ͨ������ʹ��״̬��������������
	IBP_Err_Channel_Used_In_Playing,						///<¼��ط�-ͨ������ʹ��״̬������¼��ط�����
	IBP_Err_RtspToken_Invalid,								///<rtsp token��Ч
	IBP_Err_Channel_In_Closing,								///<ͨ���������ڹر�״̬
	IBP_Err_Not_Find_Channel,								///<δ�ҵ�ͨ��
	IBP_Err_Rtsp_Disconnect,								///<rtsp���ӶϿ�
	IBP_Err_Cascade_Connect,								///<���Ӽ�������ʧ��
	IBP_Err_No_Port_For_Use,								///<û�ж˿ڿ�ʹ��
	IBP_Err_Play_No_Setup,									///<����rtsp playǰδ����setup��Ϣ
	IBP_Err_RTP_Build,										///<�����������罨��ʧ��
	IBP_Err_Add_Node_Into_SendList,							///<���뷢���б�ʧ��
	IBP_Err_Delete_Node_Failed,								///<ɾ��nodeʧ��
	IBP_Err_Record_Download_Finished,						///<¼���������
	IBP_Err_No_Record_Files,								///<û��¼���ļ�
	IBP_Err_Receiver_Net_Build,								///<�������������罨��ʧ��
	IBP_Err_SS_Open_File_Failed,							///<ss���ļ�ʧ��
	IBP_Err_Msg_Save_Timeout,								///<��Ϣ���泬ʱ
	IBP_Err_Not_Find_PlayInfo,								///<�Ҳ���������Ϣ
	IBP_Err_Red5_Connect,									///<����red5ʧ��
	IBP_Err_Query_UserId_Failed,							///<��ѯ�û�IDʧ��
	IBP_Err_Get_ChannelIndex_Failed,						///<��ȡͨ������ʧ��
	IBP_Err_Not_Find_USB_Proxy,								///<��ȡusb�������ʧ��
	IBP_Err_Red5_Connech_Already,							///<��red5�������Ѿ�����
	IBP_Err_Notfound_Startvideo_Request,					///<û���ҵ�������Ϣ
	IBP_Err_Notfound_Active_Url,							///<û���ҵ���Ч��URL
	IBP_Err_Rtcp_Timeout,									///<RTCP��ʱ
	IBP_Err_Not_Find_Source_Msg,							///<�Ҳ���ԭʼ��Ϣ
	IBP_Err_Msg_Is_Not_Fit,									///<�����ʵ���Ϣ
	IBP_Err_User_Right_Alter,								///<�û�Ȩ���޸ģ��޸��豸��ƵȨ��
	IBP_Err_VTDU_End = 1199,								///<VTDU����
	
	IBP_Err_DMU_Begin = 1200,								///<DMU��ʼ
	IBP_Err_DEVICE_OFFLINE,									///<�������豸����
	IBP_Err_PTZCONTROL_BYSENIOR,							///<�߼��û�������̨����
	IBP_Err_PTZCONTROL_ASSENIOR,							///<��ռ�ͼ��û�����̨����Ȩ
	IBP_Err_PTZCONTROL_LOCKBYOTHER,							///<��̨�������û�����
	IBP_Err_PTZCONTROL_NOTLOCK,								///<��̨û������
	IBP_Err_SERVICE_UNAVAILABLE,							///<��ǰDMU���񲻿���
	IBP_Err_MASTER_SENDTO_SLAVE,							///<Master��Slave����ʧ��
	IBP_Err_UPMASTER_SENDTO_UPMASTER,						///<UpMaster��LowMaster����ʧ��
	IBP_Err_UNKNOWMODLE,									///<DMU���Unknown
	IBP_Err_LOGIN_SAMEIPPORT,								///<�ظ���¼�豸
	IBP_Err_LOGIN_DEVICE_FAIL,								///<��¼�豸ʧ��
	IBP_Err_SCS_OPT_FAILURE,								///<��������ʧ��
	IBP_Err_NOT_FIND_DEVID_BY_DOMCODE,						///<����DomCode��û���ҵ�DevId
	IBP_Err_CANNOT_MODIFY_PREPOINT,							///<�����޸�Ԥ��λ����Ϊ����һ���豸
	IBP_Err_FETCH_GRAPHY_BUSY,								///<����ץͼ�����Ժ�����
	IBP_Err_FETCH_GRAPHY_UNKNOWN_ERROR,						///<ץͼδ֪����
	IBP_Err_FETCH_GRAPHY_DEVICE_OFF,						///<ץͼ�����豸����
	IBP_Err_PTZCONTROL_LOCKBYSELF,							///<��̨�Ѿ����Լ�����
	IBP_Err_DMU_OTHERQUERYING,								///<�����û�����ѯ
	IBP_Err_CANNOT_SUPPORT_DECORDER_TYPE,                   ///<��֧�ֵĽ���������
	IBP_Err_PASSWORD_DUPLICATE,                             ///<�����ظ�
	IBP_Err_TERMINAL_EXIST_UNDER_ORG,						///<��֯�������ն˲���ɾ����֯

	IBP_ERR_ADAPTER_SDK_OPTTASK_FAILED,						///<�����㲥ϵͳ����ʧ��
	IBP_ERR_ADAPTER_SDK_MODIFYTERMINAL_FAILED,				///<�޸Ĺ㲥ϵͳ�ն���Ϣʧ��
	IBP_ERR_ADAPTER_SDK_UPDATE_TERMINAL_FAILED,				///<��ѯ�㲥ϵͳ�ն���Ϣʧ�ܣ���ȡ�����ն���Ϣ������
	IBP_ERR_ADAPTER_SDK_QUERY_CURRENTFILE,					///<��ѯ�㲥��ǰ�����ļ�ʧ��

	IBP_Err_POS_SERVICE_DISC,                               ///<��λ������δ���� 2018.6.28 xmchen add 
	IBP_Err_DMU_End = 1299,									///<DMU����
	
	IBP_Err_VRU_Begin = 1300,								///<VRU����
	IBP_Err_NOSLAVE_AVALIABLE,								///<û��Slave����
	IBP_Err_NOTSUPPORTED,									///<���ܲ�֧��
	IBP_Err_DATABASE_FAILED,								///<���ݿ����ʧ��
	IBP_Err_PlanData_Empty,									///<�ƻ�����Ϊ��
	IBP_Err_VRU_Start_Unfinished,							///<vru����δ���
	IBP_Err_Not_Find_VTDU,									///<δ�ҵ�vtdu
	IBP_Err_RtspConnect_Failed,								///<
	IBP_Err_CreateChannel_Failed,							///<
	IBP_Err_RTP_Build_Failed,								///<
	IBP_Err_No_RtpPort_For_Use,								///<
	IBP_Err_Channel_Used_In_Storing,						///<ͨ������ʹ��״̬�����ڴ洢
	IBP_Err_AddStreamId_Failed,								///<�洢ʱ�����idʧ��
	IBP_Err_Receive_Data_Timeout,							///<����������ʱ
	IBP_Err_Server_Disconnect,								///<�ͷ�������ӶϿ�
	IBP_Err_Device_Disconnect,								///<�豸���ӶϿ�
	IBP_Err_Add_CqfsSession_Failed,							///<���cqfssessionʧ��
	IBP_Err_ReceiveStream_Timeout,							///<��������ʱ
	IBP_Err_Right_Alter,									///<Ȩ�޸ı�
	IBP_Err_Device_Alter,									///<�豸��Ϣ�ı�
	IBP_Err_Synopsis_AddTask_Err,							///<netsdk���Ũ���������
	IBP_Err_Synopsis_SetCallBack_Err,						///<netsdk����Ũ��״̬�ص�����
	IBP_Err_VRU_DeleteClip_Failded,                         ///<vruɾ��clipʧ��
	IBP_Err_VRU_GetDiskFreeSpace_Failded,                   ///<vru��ȡʣ��ռ�ʧ��
	IBP_Err_VRU_NotOpenOtherDomidVideo,                     ///<vru�޷�����������Ƶ
	IBP_Err_VRU_StreamId_Delete,                            ///<vru��ID�Ѿ���ɾ��
	IBP_Err_VRU_End = 1399,									///<VRU����
	
	IBP_Err_LKU_Begin = 1400,								///<LKU����
	IBP_Err_LKU_End = 1499,									///<LKU����
	
	IBP_Err_LMU_Begin = 1500,								///<LMU����
	IBP_Err_LMU_QueryUserBindTelePhone_Empty,				///��ѯ��֯���û����ֻ�������Ϊ��
	IBP_Err_LMU_End = 1599,									///<LMU����
	
	IBP_Err_UAS_Begin = 1600,								///<UAS�����뿪ʼ
	IBP_Err_UAS_Cmu,										///<UAS��CMUģ�����
	IBP_Err_UAS_Dmu_Master,									///<UAS��Dmu Masterģ�����
	IBP_Err_UAS_Dmu_Slave,									///<UAS��Dmu Slaveģ�����
	IBP_Err_UAS_Vtdu,										///<UAS��Vtduģ�����
	IBP_Err_UAS_Logic,										///<UAS���߼�ģ�����
	IBP_Err_UAS_Sip,										///<UAS��Sip����
	IBP_Err_UAS_Rtsp,										///<UAS��Rtsp����
	IBP_Err_UAS_Pg,											///<UAS��Pg����
	IBP_Err_UAS_Res,										///<UAS��Ӧ��Э�����
	IBP_Err_UAS_Res_Not_Find,								///<UAS�յ�Ӧ��δ�ҵ��豸
	IBP_Err_UAS_Res_Not_Right,								///<UAS�յ�Ӧ�����豸Ȩ��
	IBP_Err_UAS_Res_Login_Fail,								///<UAS�յ�Ӧ���½�豸ʧ�ܻ��豸������
	IBP_Err_UAS_Sip_Res_Timeout,							///<UAS��SIP��ʱδ�յ�Ӧ��
	IBP_Err_UAS_Platform,									///<UAS���¼�������ʧ��
	IBP_Err_UAS_Cookie_Invalid,								///<UAS��cookieʧЧ
	IBP_Err_UAS_Login,										///<UASδ��¼
	IBP_Err_UAS_End = 1699,									///<UAS���������
	
	IBP_Err_UAC_Begin = 1700,								///<UAC�����뿪ʼ
	IBP_Err_UAC_End = 1799,									///<UAC���������
	
	IBP_ERR_ADAPTER_BEGIN = 1800,							///<�豸��������ʼ
	IBP_ERR_ADAPTER_CANNOT_FIND_DEV,						///<û���ҵ��豸����
	IBP_ERR_ADAPTER_DYNAMICCAST_FAILD,						///<ת������
	IBP_ERR_ADAPTER_DVR_IPPORT_DUP,							///<DVR IP Port
	IBP_ERR_ADAPTER_DLL_LOAD_FAIL,							///<DLL���ش���
	IBP_ERR_ADAPTER_PARAMTER_ERROR,							///<��������
	IBP_ERR_ADAPTER_DEVICE_OFFLINE,							///<�豸����
	IBP_ERR_ADAPTER_START_LISTEN_FAILED,					///<��������ע�����ʧ��

	IBP_ERR_ADAPTER_SDK_BEGIN = 1850,						///<������SDK��ʼ
	IBP_ERR_ADAPTER_SDK_USER_PASSWORD_ERROR,				///<�û��������
	IBP_ERR_ADAPTER_SDK_LOG_TIMEOUT,						///<��½��ʱ
	IBP_ERR_ADAPTER_SDK_USER_LOCKED,						///<�û�����
	IBP_ERR_ADAPTER_SDK_ILLEGAL_USER,						///<�Ƿ��û�
	IBP_ERR_ADAPTER_SDK_RESOURCE_ERROR,						///<��Դ����
	IBP_ERR_ADAPTER_SDK_LOGNET_ERROE,						///<�������
	IBP_ERR_ADAPTER_SDK_PING_ERROE,							///<PING����
	IBP_ERR_ADAPTER_SDK_MAX_USERNUM,						///<��������û�����
	IBP_ERR_ADAPTER_SDK_REAL_PLAY,							///<ʵʱ��Ƶ����
	IBP_ERR_ADAPTER_SDK_VEDIO_STOP,							///<��Ƶֹͣ
	IBP_ERR_ADAPTER_SDK_REAL_TALK,							///<�����Խ�
	IBP_ERR_ADAPTER_SDK_TALK_STOP,							///<�Խ�ֹͣ
	IBP_ERR_ADAPTER_SDK_CHANNEL_USED_IN_PLAYING,			///<��ͨ���û�����ʹ��
	IBP_ERR_ADAPTER_SDK_RECORD_DOWNLOAD_FINISHED,			///<¼���������
	IBP_ERR_ADAPTER_SDK_LOGIN_DEVICE_FAIL,					///<��½�豸ʧ
	IBP_ERR_ADAPTER_SDK_API,								///<API����
	IBP_ERR_ADAPTER_SDK_API_FAILED,							///<API����ʧ��
	IBP_ERR_ADAPTER_SDK_CREAT_DEVICE_FAILED,				///<�����豸ʧ��
	IBP_ERR_ADAPTER_SDK_NOW_UNAVAILABLE=1869,				///<��ǰ�޷�ִ��
	IBP_ERR_ADAPTER_END = 1899,								///<�豸����������
	
	IBP_Err_MCU_Begin = 1900,								///<MCU��ʼ
	IBP_Err_MCU_UNKNOWMODEL,								///<����ģʽΪUnknown
	IBP_Err_MCU_NOT_MASTER,									///<����master
	IBP_Err_MCU_INVALID_CONNECTION,							///<��Ч����
	IBP_Err_MCU_INVALID_PARAM,								///<��Ч����
	IBP_Err_MCU_NO_USER_ID,									///<�û�id������
	IBP_Err_MCU_NO_IMSDINFO,								///<�û�������IMDS��Ϣ�Ҳ���
	IBP_Err_MCU_KEY_CONFLICT,								///<�ؼ��ֳ�ͻ
	IBP_Err_MCU_PASSWORD_INVALID,							///<�������
	IBP_Err_MCU_LOGIN_ALREADY,								///<�Ѿ���¼
	IBP_Err_MCU_MEETING_ID_INVALID,							///<������id��Ч
	IBP_Err_MCU_NOT_LOGIN,									///<û�е�¼
	IBP_Err_MCU_MEETING_LOCKED,								///<�����ұ�����
	IBP_Err_MCU_NO_SIP_SERVER,								///<û��sip������
	IBP_Err_MCU_SIP_INIT,									///<sip��ʼ��ʧ��
	IBP_Err_MCU_SIP_REGISTER,								///<sip ע��ʧ��
	IBP_Err_MCU_NOT_MAINSPEAKER,							///<����������
	IBP_Err_MCU_USER_OFFLINE,								///<�û�������
	IBP_Err_MCU_SESSION_INVALID,							///<��Чsession
	IBP_Err_MCU_NO_CALLERNUMBER,							///<���������к������
	IBP_Err_MCU_HOOK_ERR,									///<ժ������
	IBP_Err_MCU_MAX_USER_LIMIT,								///<�ﵽ�û����������
	IBP_Err_MCU_IMDS_OFFLINE,								///<IMDS��������
	IBP_Err_MCU_MEET_NOT_MODIFY,							///<��������в����޸�
	IBP_Err_MCU_EMERGENCY_MEETING_EXIST,					///<�Ѿ�����Ӧ������
	IBP_Err_MCU_PHONE_IS_CALLING,							///<�绰���ڲ�����
	IBP_Err_MCU_PHONE_STATE_WRONG,							///<�绰״̬����
	IBP_Err_MCU_FEATURE_NOT_SUPPORTED,						///<��֧�ָù���
	IBP_Err_MCU_COLLECTION_IS_EXISTED,						///<��ϵ����Ϣ�Ѿ����ղ�
	IBP_Err_MCU_ROOM_IS_NOT_EXISTED,						///<�����Ҳ�����
	IBP_Err_MCU_ADGU_OFFLINE,								///<ADGU��������
	IBP_Err_MCU_MEMBER_IS_IN_THE_MEETING,					///<�Ѿ��ڻ�������
	IBP_Err_MCU_DOMAIN_ERROR,								///<�����
	IBP_Err_MCU_MEMBER_IS_IN_OTHER_MEETING,					///<�û��Ѿ���������������
	IBP_Err_MCU_MEETING_IS_NOT_EXISTED,						///<���鲻����
	IBP_Err_MCU_MAIN_SPEAKER_IS_NOT_EXISTED,				///<�����˲�����
	IBP_Err_MCU_MEETING_ROOM_EXIST,							///<�������Ѿ�����
	IBP_ERR_MCU_PHONE_HANGUP_TIMELATE,						///�����Ҷϻ���г�ʱ
	IBP_Err_MCU_End = 1999,									///<MCU����
	
	IBP_Err_IIS_Begin = 2000,								///< IIS ��ʼ
	IBP_Err_IIS_NOT_MASTER,									///<����master
	IBP_Err_IIS_PlanNotExist,								///<�ƻ�������
	IBP_Err_IIS_UnknownOpt,									///<δ֪����
	IBP_Err_IIS_AddTaskFail,								///<�������ʧ��
	IBP_Err_IIS_UpdateTaskFail,								///<�������ø���ʧ��
	IBP_Err_IIS_DeleteTaskFail,								///<����ɾ��ʧ��
	IBP_Err_IIS_AddPointFail,								///<���Ѳ���ʧ��
	IBP_Err_IIS_UpdatePointFail,							///<����Ѳ���ʧ��
	IBP_Err_IIS_DeletePointFail,							///<ɾ��Ѳ���ʧ��
	IBP_Err_IIS_AddTimeSchduleFail,							///<���ʱ��ģ��ʧ��
	IBP_Err_IIS_UpdateTimeSchduleFail,						///<����ʱ��ģ��ʧ��
	IBP_Err_IIS_DeleteTimeSchduleFail,						///<ɾ��ʱ��ģ��ʧ��
	IBP_Err_IIS_QueryTaskFail,								///<��ѯ����ʧ��
	IBP_Err_IIS_QueryPointFail,								///<��ѯѲ���ʧ��
	IBP_Err_IIS_QueryTimeTemplateFail,						///<��ѯʱ��ģ��ʧ��
	IBP_Err_IIS_CreatePlayFailed,							///<��������Instanceʧ��
	IBP_Err_IIS_SnapshotFailed,								///<ץͼʧ��
	IBP_Err_IIS_ExcutePlanFailed,							///<�ƻ�ִ�гɹ���ʧ��
	IBP_Err_IIS_PlanStarted,								///<�ƻ��Ѿ���ʼ
	IBP_Err_IIS_PlanStopped,								///<�ƻ��Ѿ�����
	IBP_Err_IIS_CalIrIndexError,							///<����ָ�����ʧ��
	IBP_Err_IIS_CalIrTempDiffError,							///<�����²����ʧ��
	IBP_Err_IIS_PlanSubscribeFailed,						///<�ƻ�����ʧ��
	IBP_Err_IIS_NoAvailableSlaver,							///<û�п��õĴӻ�
	IBP_Err_IIS_PanelParam1Error,							///<�Ǳ����-��һ����������
	IBP_Err_IIS_PanelParam2Error,							///<�Ǳ����-�ڶ�����������
	IBP_Err_IIS_IVPEError,									///<�Ǳ�������������
	IBP_Err_IIS_End = 2099,									///<IIS����
	
	IBP_Err_FS_Begin = 2100,								///<FS ��ʼ
	IBP_Err_FS_NOT_MASTER,									///<����master
	IBP_Err_FS_End = 2199,									///<FS����
	
	IBP_Err_ADGU_Begin = 2200,								///<ADGU��ʼ
	IBP_Err_ADGU_UNKNOWMODEL,								///<����ģʽΪUnknown
	IBP_Err_ADGU_NOT_MASTER,								///<����master
	IBP_Err_ADGU_INVALID_CONNECTION,						///<��Ч����
	IBP_Err_ADGU_INVALID_PARAM,								///<��Ч����
	IBP_Err_ADGU_NO_USER_ID,								///<�û�id������
	IBP_Err_ADGU_KEY_CONFLICT,								///<�ؼ��ֳ�ͻ
	IBP_Err_ADGU_RTSP,										///<ADGU��Rtsp����
	IBP_Err_ADGU_IPPORT,									///<ADGU��ַ����
	IBP_Err_ADGU_ID_MAPPING,								///<ADGU�豸idӳ�����
	IBP_Err_ADGU_VIDEO_IS_OPEN,								///<ADGU����Ƶ�Ѵ�
	IBP_Err_ADGU_INVITE_FAILED,								///<ADGU  INVITE����ʧ��
	IBP_Err_ADGU_VIDEO_HAS_BEEN_CLOSED,						///<ADGU��Ƶ�Ѿ����ر�
	IBP_Err_ADGU_BYE_FAILED,								///<ADGU  BYE����ʧ��
	IBP_Err_ADGU_CAN_NOT_GET_RTP_INFO,						///<ADGU��ȡRTP��Ϣʧ��
	IBP_Err_ADGU_MEDIA_SESSION_IS_NULL,						///<ADGUý����ϢΪ��
	IBP_Err_ADGU_SEND_MSG_CMU,								///<ADGU ������Ϣ��CMUʧ��
	IBP_Err_ADGU_IPC_CALLED,								///<����ͨ��
	IBP_Err_ADGU_IPC_GET_DEV,								///<��ȡ�豸��Ϣʧ��
	IBP_Err_ADGU_IPC_GET_DEV_BY_CHNL,						///<����ͨ����ȡ�豸��Ϣʧ��
	IBP_Err_ADGU_IPC_LOGIN_FAILED,							///<��¼�豸ʧ��
	IBP_Err_ADGU_IPC_NOT_FIND_DEV,							///<�Ҳ����豸��Ϣ
	IBP_Err_ADGU_IPC_LOGIN_NO_DEV,							///<�Ҳ����Ѿ���¼���豸
	IBP_Err_ADGU_IPC_ADD_TRANSFER,							///<���ת���ڵ�ʧ��
	IBP_Err_ADGU_AUDIO_CALL,								///<�������в��ܴ���Ƶ
	IBP_Err_ADGU_IPC_PLAY,									///<����Խ�ʧ��
	IBP_Err_ADGU_Chnl_Unsupport,							///<��ͨ����֧��
	IBP_Err_ADGU_End = 2299,								///<ADGU����
	
	IBP_Err_VMU_Begin = 2300,								///<VMU��ʼ
	IBP_Err_VMU_UNKNOWMODEL,								///<����ģʽΪUnknown
	IBP_Err_VMU_NOT_MASTER,									///<����master
	IBP_Err_VMU_INVALID_CONNECTION,							///<��Ч����
	IBP_Err_VMU_INVALID_PARAM,								///<��Ч����
	IBP_Err_VMU_KEY_CONFLICT,								///<�ؼ��ֳ�ͻ
	IBP_Err_VMU_RTSP,										///<VMU��Rtsp����
	IBP_Err_VMU_IPPORT,										///<VMU��ַ����
	IBP_Err_VMU_SERVER_NOT_REGISTER,						///<VMUû��ע��
	IBP_Err_VMU_NOT_FOUND_NVD,								///<û���ҵ�NVD
	IBP_Err_VMU_ENCODE_PDU,									///<
	IBP_Err_VMU_DECODE_PDU,									///<
	IBP_Err_VMU_SERVER_RETURN_ERR,							///<VMU���񷵻�ʧ��
	IBP_Err_VMU_End = 2399,									///<VMU����
	
	IBP_Err_LCU_Begin = 2400,								///<LCU��ʼ
	IBP_Err_LCU_UNKNOWMODEL,								///<����ģʽΪUnknown
	IBP_Err_LCU_NOT_MASTER,									///<����master
	IBP_Err_LCU_INVALID_CONNECTION,							///<��Ч����
	IBP_Err_LCU_INVALID_PARAM,								///<��Ч����
	IBP_Err_LCU_ENCODE_PDU,									///<
	IBP_Err_LCU_DECODE_PDU,									///<
	IBP_Err_LCU_USER_OFFLINE,								///<�û�����
	IBP_Err_LCU_GROUP_UNEXIST,								///<�鲻����
	IBP_Err_LCU_GROUPID_REPEAT,								///<��id�ظ�
	IBP_Err_LCU_GROUPMEMBER_UNEXIST,						///<���Ա������
	IBP_Err_LCU_USER_UNEXIST,								///<�û�������
	IBP_Err_LCU_USER_EXISTED,								///<�û��Ѿ�����
	IBP_Err_LCU_DEVICE_UNEXIST,								///<�豸������
	IBP_Err_LCU_DEVICE_EXISTED,								///<�豸�Ѿ�����
	IBP_Err_LCU_DELMEMBER_FAIL,					        	///<ɾ����Աʧ��
	IBP_Err_LCU_NOAUTHORITY,					        	///<�޲���Ȩ��
	IBP_Err_LCU_MKDIR_FAIL,					        		///<����Ŀ¼ʧ��
	IBP_Err_LCU_DWFILE_FAIL,					        	///<�����ļ�ʧ��
	IBP_Err_LCU_FILE_UNEXIT,					        	///<�ļ�������
	IBP_Err_LCU_FILEOPEN_FAIL,					        	///<�ļ���ʧ��
	IBP_Err_LCU_GROUP_BUSY,					        		///<Ⱥ�����ڿ���
	IBP_Err_LCU_OPTROOM_FAIL,					        	///<��ɾ�Ļ�����ʧ��
	IBP_Err_LCU_AUDIOROOM_UNEXIST,					        ///<�����Ҳ�����
	IBP_Err_LCU_EQUIPMENT_UNSUPPORT,					    ///<�豸��֧��
	IBP_Err_LCU_ADDROOM_FAIL,								 ///<���������ʧ��
	IBP_Err_LCU_BUSY,								        ///<�û����ڴ���������Ϣ
	IBP_Err_LCU_FILETYPE_ERR,								///<�ļ���ʽ����
	IBP_Err_LCU_USER_NOT_INMEETING,							///<�û����ڻ�����

	IBP_Err_LCU_TASK_UNDONE,								///<������û�����
	IBP_Err_LCU_ALARM_REPEART,								///<�и澯�ظ�
	IBP_Err_LCU_USER_NOT_IN_GROUP,							///<�û�����Ⱥ
	IBP_Err_LCU_ALARM_UNEXIST,								///<�и澯������
	IBP_Err_LCU_CASE_EXISTED,								///<�����ظ�
	IBP_Err_LCU_Call_Fail,									///<����ʧ��
	IBP_Err_LCU_Call_Unaccept,								///<�ܾ�����
	IBP_Err_LCU_Write_Case,									///<���Ӱ���ʧ��
	IBP_Err_LCU_Case_Unexisted,								///<����������
	IBP_Err_LCU_THIS_DEVICE_IS_EXCUTING_CASE,				///<�Ѿ���ִ�и��豸������
	IBP_Err_LCU_THIS_DEVICE_IS_NOT_EXCUTING_CASE,			///<û��ִ�и��豸������
	IBP_Err_LCU_THE_ALARM_HAVE_CASE,						///<�澯�Ѿ���������
	IBP_Err_LCU_DEV_OPT_RIGHT_OVERTIME,						///<��Ƶ�������ʱȨ���ѹ���
	IBP_Err_LCU_No_ALARM,									///<û�и澯��Ϣ
	IBP_Err_LCU_CASEID_NULL,								///<����idΪ��
	IBP_Err_LCU_CHANGE_CREATER_FAILED,						///<�޸İ����Ӿ�����Ϣʧ��
	IBP_Err_LCU_GET_RELATEDALARM_FAILED,					///<ȡ�ð��������澯��Ϣʧ��
	IBP_Err_LCU_RELATEDALARM_NOEXIST,					    ///<���������澯��ϢΪ0
	IBP_Err_LCU_CHANGE_REPORTER_FAILED,						///<�޸İ�����������Ϣʧ��
	IBP_Err_LCU_TASK_RECIVER_INVALID,						///<��������߷Ƿ�
	IBP_Err_LCU_CHANGE_EVENT_FAILED,						///<�޸İ����¼���Ϣʧ��

	IBP_Err_LCU_End = 2499,									///<LCU����

	IBP_Err_License_Begin = 2500,							///<License��ʼ
	IBP_Err_License_DevTypeNotSupported,					///<License��֧�ָ��豸����
	IBP_Err_License_ManufactureNotSupported,				///<License��֧�ָó�������
	IBP_Err_License_UserTypeNotSupported,					///<License��֧�ָ��û�����
	IBP_Err_License_DevNumberNotSupported,					///<�������豸��������License����
	IBP_Err_License_UserNumberNotSupported,					///<�������û���������License����
	IBP_LICENSE_DEVADD_DENY,								///<�ܾ�����豸
	IBP_LICENSE_DEVTYPE_DENY,								///<�ܾ���Ӹ��豸����
	IBP_LICENSE_ACCEPT_OVER,								///<license������������
	IBP_Err_License_RunTimeError,							///<����ʱ�䳬��License����
	IBP_Err_License_End = 2699,								///<License����

	IBP_Err_Cmm_Begin = 2700,								///<Cmm��ʼ
	IBP_Err_Cmm_Not_Master = 2701,							///<Cmm����master
	IBP_Err_Cmm_End = 2799,									///<Cmm����

	IBP_Err_OMU_Begin = 2800,									///<OMU��ʼ
	IBP_Err_OMU_NOT_MASTER,									///<����master
	IBP_Err_OMU_End = 2999,									///<OMU����

	IBP_Err_DTCU_Begin = 3000,								///<DTCU��ʼ
	IBP_Err_DTCU_UNKNOWMODEL,								///<����ģʽΪUnknown
	IBP_Err_DTCU_NOT_MASTER,								///<����master
	IBP_Err_DTCU_End = 3199,								///<DTCU����

	IBP_Err_SDK_Begin = 10000,								///<SDK��ʼ
	IBP_Err_SDK_Com_Begin = 10000,							///<SDKͨ�ÿ�ʼ
	IBP_Err_SDK_Com_Timeout = 10000,						///<��ʱ
	IBP_Err_SDK_Com_NotFound_OriReq,						///<û���ҵ�ԭʼ������Ϣ
	IBP_Err_SDK_Com_ReqRes_NotSeq,							///<����ͻظ�����Բ�����
	IBP_Err_SDK_Com_Res_NULL,								///<�ظ���ϢΪ��
	IBP_Err_SDK_Com_LenOver,								///<���Ȳ���
	IBP_Err_SDK_Manager_Failed,								///<SDK manager ��ʼ��ʧ��
	IBP_Err_SDK_Thread_Failed,								///<SDK �����߳�ʧ��
	IBP_Err_SDK_UserCheck_Failed,							///<�û�����У��ʧ��
	IBP_Err_SDK_Response_Null,								///<������Ϣ��Ϊ��
	IBP_Err_SDK_ConnectServer_Error,						///<SDK���ӷ������
	IBP_Err_SDK_NO_INIT,									///<û�г�ʼ��
	IBP_Err_SDK_Notify,										///<Notifyʧ�ܣ���׿��ϵͳ���ָ���
	IBP_Err_SDK_NotTcpMedia,								///<��ΪTCP����
	IBP_Err_SDK_GetTcpBuffFail,								///<��ȡTCP�����������ѻ�����ʧ��
	IBP_Err_SDK_Com_End	= 10999,							///<SDKͨ�ý���
	
	IBP_Err_SDK_CMU_Begin = 11000,							///<CMU��ʼ
	IBP_Err_SDK_CMU_End = 11099,							///<CMU����
	
	IBP_Err_SDK_VTDU_Begin = 11100,							///<VTDU��ʼ
	IBP_Err_SDK_Not_Connect,								///<δ����vtdu
	IBP_Err_SDK_Not_Find_Session,							///<δ�ҵ�session
	IBP_Err_SDK_No_RtspConnect,								///<δ����rtsp����
	IBP_Err_SDK_No_RtspSetup,								///<δ����setup����
	IBP_Err_SDK_No_RtspPlay,								///<δ����play����
	IBP_Err_SDK_RTP_Connect_Failed,							///<�������ܶԶ˽���ʧ��
	IBP_Err_SDK_VTDU_End = 11199,							///<VTDU����
	
	IBP_Err_SDK_DMU_Begin = 11200,							///<DMU��ʼ
	IBP_Err_Has_User_RevAlarm,                              //�Ѿ����û��Ӿ�
	IBP_Err_SDK_DMU_End = 11299,							///<DMU����
	
	IBP_Err_SDK_VRU_Begin = 11300,							///<VRU��ʼ
	IBP_Err_SDK_RtspConnect_Failed,							///<
	IBP_Err_SDK_VRU_End = 11399,							///<VRU����
	
	IBP_Err_SDK_LKU_Begin = 11400,							///<LKU��ʼ
	IBP_Err_SDK_LKU_End = 11499,							///<LKU����
	
	IBP_Err_SDK_LMU_Begin = 11500,							///<LMU��ʼ
	IBP_Err_SDK_LMU_End = 11599,							///<LMU����
	
	IBP_Err_SDK_FS_Begin = 11600,							///<FS��ʼ
	IBP_Err_SDK_Generate_GUID_Failed,						///<�����ļ�GUIDʧ��
	IBP_Err_SDK_File_GUID_Invalid,							///<�ļ�GUID��Ч
	IBP_Err_SDK_FileInfo_Wrong,								///<�ļ���Ϣ��д����
	IBP_Err_SDK_FilePath_Wrong,								///<�ļ�·����д��д����
	IBP_Err_SDK_File_Open_Failed,							///<�ļ���ʧ��
	IBP_Err_SDK_File_Exist,									///<ͬ���ļ��Ѵ���
	IBP_Err_SDK_File_Not_Exist,								///<�ϴ�/�����ļ�������
	IBP_Err_SDK_File_Size_Limited,							///<�ϴ��ļ�̫�󣨳���2G��
	IBP_Err_SDK_Disk_Full,									///<����/���������̿ռ�����
	IBP_Err_SDK_File_In_Use,								///<�ļ�����ʹ��,�����ϴ�����������
	IBP_Err_SDK_FileInfo_Lost,								///<�ڴ����ļ���Ϣ��ʧ,����д�����ݿ�
	IBP_Err_SDK_Logic_Wrong,								///<�߼�������Ҫ�޸�
	IBP_Err_SDK_New_Buf_Failed,								///<����ռ�ʧ��
	IBP_Err_SDK_Write_Database_Failed,						///<д�����ݿ�ʧ��
	IBP_Err_SDK_File_Del_Failed,							///<�ļ�ɾ��ʧ��
	IBP_Err_SDK_File_Downloading,							///<�ļ�����������
	IBP_Err_SDK_Make_Dir_Failed,							///<�����ļ���ʧ��
	IBP_Err_SDK_FS_End = 11799,								///<FS����
	
	IBP_Err_SDK_ADAPTER_Begin = 11800,						///<SDK ADAPATER ��ʼ
	IBP_Err_SDK_ADAPTER_SnapshotFailed,						///<ץͼʧ��
	IBP_Err_SDK_ADAPTER_PacketDataFailed,					///<���ʧ��
	IBP_Err_SDK_ADAPTER_ParseDataFailed,					///<����ʧ��
	IBP_Err_SDK_ADAPTER_End = 11899,						///<SDK ADAPATER����
	
	IBP_Err_SDK_CMM_Begin = 11900,							///<SDK CMM ��ʼ
	IBP_Err_SDK_CMM_Is_Not_Connected,						///<CMMû������
	IBP_Err_SDK_CMM_No_Function,							///<CMMû�д�����
	IBP_Err_SDK_CMM_Sys_Code_Conflict,						///<��ϵͳcode�ֶγ�ͻ
	IBP_Err_SDK_CMM_End = 11999,							///<SDK CMM����
	
	IBP_Err_SDK_IMS_Begin = 12000,							///<SDK IMS ��ʼ
	IBP_Err_SDK_IMS_MSG_ERR,								///<IMS��Ϣ����
	IBP_Err_SDK_IMS_End = 12099,							///<SDK IMS����
	
	IBP_Err_CANNOT_FIND_FUNCTION = 13900,					///<���Ҳ����ú���
	IBP_Err_CANNOT_LOGIN_MORE_PLATFORM,						///<�޷���½�����ƽ̨
	IBP_Err_Not_Find_PlatForm,								///<�޷��ҵ���ƽ̨
	IBP_Err_PlatForm_OffLine,								///<��ƽ̨����
	IBP_Err_Not_Find_DMU,									///<�޷��ҵ�DMU
	IBP_Err_Not_Find_IIS,									///<�޷��ҵ�IIS
	IBP_Err_Not_Find_IMDS,									///<�޷��ҵ�IMDS
	IBP_Err_Not_Find_FS,									///<�޷��ҵ�FS
	IBP_Err_Not_Find_LMU,									///<�޷��ҵ�lmu

	IBP_Err_PLAY_Begin = 14000,								///<SDK���ſⲿ�ֿ�ʼ
	IBP_Err_PLAY_LoadLibraryFailed,							///<���ؽ����ʧ��
	IBP_Err_PLAY_GetProcAddrFailed,							///<���ؽ���⺯����ַʧ��
	IBP_Err_PLAY_CannotCreateInvalidChannel,				///<�޷�����һ������Ϊ����Ч����Ƶ��
	IBP_Err_PLAY_NoneFreePort,								///<����Ƶ��ʧ�ܣ������û�п��е�port��
	IBP_Err_PLAY_NoneFreeChannel,							///<���벻������Ƶ��
	IBP_Err_PLAY_OutBoundChannel,							///<Ƶ����Խ��
	IBP_Err_PLAY_ReleaseFreeChannel,						///<�޷��ͷſ��е�Ƶ��
	IBP_Err_PLAY_CannotOperateFreeChannel,					///<�޷��������е�Ƶ��

	IBP_Err_PLAY_CannotPlayWhenNotStreamType,				///<��ǰ��������ģʽ���޷�����
	IBP_Err_PLAY_CannotPlayWhenIsPlaying,					///<��ǰ�����ڲ����У��޷�����
	IBP_Err_PLAY_CannotPlayWhenNoneWindow,					///<��ǰ��δ��Ӵ��ڣ��޷�����
	IBP_Err_PLAY_SetStreamOpenModeFailed,					///<�������򿪵�ģʽʱʧ��
	IBP_Err_PLAY_OpenStreamFailed,							///<����ʧ��
	IBP_Err_PLAY_SetDisplayBufFailed,						///<������ʾ����ʧ��
	IBP_Err_PLAY_PlayStreamFailed,							///<������ʧ��
	
	
	IBP_Err_PLAY_CannotPlayWhenNotFileType,					///<��ǰ�������ļ�ģʽ���޷�����
	IBP_Err_PLAY_FileNameIsNull,							///<�ļ�����ΪNULL
	IBP_Err_PLAY_OpenFileFailed,							///<���ļ�ʧ��
	IBP_Err_PLAY_PlayFileFailed,							///<�����ļ�ʧ��

	IBP_Err_PLAY_CannotStopWhenIsNotPlaying,				///<��ǰ���ڲ����У��޷�ֹͣ����

	IBP_Err_PLAY_CannotInputWhenNotStreamType,				///<��ǰ��������ģʽ���޷���������
	IBP_Err_PLAY_CannotInputWhenIsNotPlaying,				///<��ǰ���ڲ����У��޷���������
	IBP_Err_PLAY_InputFailed,								///<��������ʧ��

	IBP_Err_PLAY_CannotSetDecodeWhenAudioRecording,			///<¼���ɼ�ģʽ�£��޷����ý���ģʽ
	IBP_Err_PLAY_CannotSetDecodeWhenNotStreamType,			///<��ǰ��������ģʽ���޷����ý���ģʽ
	IBP_Err_PLAY_CannotSetDecodeWhenIsNotPlaying,			///<��ǰ���ڲ����У��޷����ý���ģʽ
	IBP_Err_PLAY_SetDecodeFailed,							///<���ý���ģʽʧ��
	IBP_Err_PLAY_DoNotSupportHardDecode,					///<��ĵ��Բ�֧��Ӳ����

	IBP_Err_PLAY_CannotGetDecodeWhenAudioRecording,			///<¼���ɼ�ģʽ�£��޷���ȡ����ģʽ
	IBP_Err_PLAY_CannotGetDecodeWhenNotStreamType,			///<��ǰ��������ģʽ���޷���ȡ����ģʽ

	IBP_Err_PLAY_CannotAddMoreWindow,						///<�޷���Ӹ���Ĵ���
	IBP_Err_PLAY_CannotAddExistenceWindow,					///<�޷�����Ѵ��ڵĴ���
	IBP_Err_PLAY_CannotRemoveFirstWindowWhenPlaying,		///<�޷�ɾ�����ڲ��ŵġ���������
	IBP_Err_PLAY_CannotRemoveInexistenceWindow,				///<�޷�ɾ�������ڵĴ���

	IBP_Err_PLAY_CannotSnapWhenNotPlaying,					///<��ǰ���ڲ����У��޷�ץͼ
	IBP_Err_PLAY_CannotSnapWhenHardDecode,					///<��ǰ����Ӳ����ģʽ���޷�ץͼ
	IBP_Err_PLAY_GetPictureSizeFailed,						///<��ȡͼƬԭʼ�ߴ�ʧ��
	IBP_Err_PLAY_SnapFailed,								///<ץͼʧ��

	IBP_Err_PLAY_CannotOpenSoundWhenNotPlaying,				///<��ǰ���ڲ����У��޷�������
	IBP_Err_PLAY_OenSoundFailed,							///<������ʧ��
	IBP_Err_PLAY_CannotCloseSoundWhenNotPlaying,			///<��ǰ���ڲ����У��޷��ر�����
	IBP_Err_PLAY_CloseSoundFailed,							///<�ر�����ʧ��

	IBP_Err_PLAY_CannotGetVolumeWhenNotPlaying,				///<��ǰ���ڲ����У��޷���ȡ����ֵ
	IBP_Err_PLAY_GetVolumeFailed,							///<��ȡ����ֵʧ��
	IBP_Err_PLAY_CannotSetVolumeWhenNotPlaying,				///<��ǰ���ڲ����У��޷���������ֵ
	IBP_Err_PLAY_SetVolumeFailed,							///<��������ֵʧ��

	IBP_Err_PLAY_CannotGetColorWhenNotPlaying,				///<��ǰ���ڲ����У��޷���ȡɫ��ֵ
	IBP_Err_PLAY_GetColorFailed,							///<��ȡɫ��ֵʧ��
	IBP_Err_PLAY_CannotSetColorWhenNotPlaying,				///<��ǰ���ڲ����У��޷�����ɫ��ֵ
	IBP_Err_PLAY_SetColorFailed,							///<����ɫ��ֵʧ��

	IBP_Err_PLAY_CannotPlayControlWhenNotPlayback,			///<��ǰ���ڻط�ģʽ�£��޷����в��ſ���
	IBP_Err_PLAY_CannotPlayControlWhenNotPlaying,			///<��ǰ���ڲ����У��޷��в��ſ���
	IBP_Err_PLAY_PlayControlFailed,							///<���ſ���ʧ��

	IBP_Err_PLAY_CannotSetPositionWhenNotFileType,			///<��ǰ�����ı��ط�ģʽ�£��޷����ò��Ž���ֵ
	IBP_Err_PLAY_CannotSetPositionWhenNotPlaying,			///<��ǰ���ڲ����У��޷����ò��Ž���ֵ
	IBP_Err_PLAY_OutBoundPosition,							///<positionֵԽ��
	IBP_Err_PLAY_SetPositionFailed,							///<���ò��Ž���ʧ��
	IBP_Err_PLAY_CannotGetPositionWhenNotFileType,			///<��ǰ�����ı��ط�ģʽ�£��޷���ȡ���Ž���ֵ
	IBP_Err_PLAY_CannotGetPositionWhenNotPlaying,			///<��ǰ���ڲ����У��޷���ȡ���Ž���ֵ
	IBP_Err_PLAY_GetPositionFailed,							///<��ȡ���Ž���ʧ��

	IBP_Err_PLAY_CannotGetTotalFrameWhenNotFileType,		///<��ǰ�����ļ��ط�ģʽ�£��޷���ȡ�ļ���֡��
	IBP_Err_PLAY_CannotGetTotalFrameWhenNotPlaying,			///<��ǰ���ڲ����У��޷���ȡ�ļ���֡��
	IBP_Err_PLAY_GetTotalFrameFailed,						

	IBP_Err_PLAY_CannotGetCurrentFrameWhenNotFileType,		///<��ǰ�����ļ��ط�ģʽ�£��޷���ȡ�ļ���ǰ֡��
	IBP_Err_PLAY_CannotGetCurrentFrameWhenNotPlaying,		///<��ǰ���ڲ����У��޷���ȡ�ļ���ǰ֡��
	IBP_Err_PLAY_GetCurrentFrameFailed,						///<��ȡ�ļ���ǰ֡��ʧ��
	IBP_Err_PLAY_CannotSetCurrentFrameWhenNotFileType,		///<��ǰ�����ļ��ط�ģʽ�£��޷������ļ���ǰ֡��
	IBP_Err_PLAY_CannotSetCurrentFrameWhenNotPlaying,		///<��ǰ���ڲ����У��޷������ļ���ǰ֡��
	IBP_Err_PLAY_SetCurrentFrameFailed,						///<�����ļ���ǰ֡��ʧ��

	IBP_Err_PLAY_CannotGetCurrentTimeWhenNotPlayback,		///<��ǰ���ڻط�ģʽ�£��޷���ȡ��ǰ����ʱ��
	IBP_Err_PLAY_CannotGetCurrentTimeWhenNotPlaying,		///<��ǰ���ڲ����У��޷���ȡ��ǰ����ʱ��
	IBP_Err_PLAY_GetCurrentTimeFailed,						///<��ȡ��ǰ����ʱ��ʧ��

	IBP_Err_PLAY_CannotGetRemainWhenNotPlayback,			///<��ǰ���ڻط�ģʽ�£��޷���ȡ��ǰʣ��֡��
	IBP_Err_PLAY_CannotGetRemainWhenNotPlaying,				///<��ǰ���ڲ����У��޷���ȡ��ǰʣ��֡��
	IBP_Err_PLAY_GetRemainFailed,							///<��ȡ��ǰʣ��֡��ʧ��

	IBP_Err_PLAY_CannotGetPictureSizeWhenAudioRecording,	///<��ǰ���������ɼ��У��޷���ȡͼƬ�ߴ�
	IBP_Err_PLAY_CannotGetPictureSizeWhenNotPlaying,		///<��ǰ���ڲ����У��޷���ȡͼƬ�ߴ�

	IBP_Err_PLAY_CbIsNull,									///<�����cbΪNULL
	IBP_Err_PLAY_SetDrawCallbackFailed,						///<������ʾ�����ص�����ʧ��
	IBP_Err_PLAY_SetFileEndCallbackFailed,					///<�����ļ������ص�����ʧ��

	IBP_Err_PLAY_BuffIsNull,								///<�����buffΪNULL
	IBP_Err_PLAY_OutBoundCmd,								///<�����������Խ��
	IBP_Err_PLAY_DoNotSupportQueryMedia,					///<��֧�ֲ�ѯý����Ϣ
	IBP_Err_PLAY_QueryInfoFailed,							///<��ѯ��Ϣʧ��

	IBP_Err_PLAY_StartAudioRecordWhenNotAudioRecording,		///<��ǰ�����������ɼ�ģʽ���޷����������ɼ�
	IBP_Err_PLAY_StartAudioRecordFailed,					///<���������ɼ�ʧ��
	IBP_Err_PLAY_StopAudioRecordWhenNotAudioRecording,		///<��ǰ�����������ɼ�ģʽ���޷��ر������ɼ�
	IBP_Err_PLAY_StopAudioRecordFailed,						///<�ر������ɼ�ʧ��

	IBP_Err_PLAY_UnknownError = 14198,						///<δ֪����
	IBP_Err_PLAY_End = 14199,								///<SDK���ſⲿ�ֽ���	
	IBP_Err_SDK_Pcc_Start = 14200,							///<PCC_SDK��ʼ
	IBP_Err_SDK_Pcc_IP_Info = IBP_Err_SDK_Pcc_Start,		///<IP����ʧ��
	IBP_Err_SDK_Pcc_Media_Node,								///<û��mediaNode������
	IBP_Err_SDK_Pcc_Media_Node_Timeout,						///<���ͳ�ʱ
	IBP_Err_SDK_Pcc_Open_Local,								///<�򿪱���
	IBP_Err_SDK_Pcc_End = 14299,
	
	IBP_Err_SDK_END = 20000,								///<SDK����

}eIBP_Err;

/** @} */

#endif

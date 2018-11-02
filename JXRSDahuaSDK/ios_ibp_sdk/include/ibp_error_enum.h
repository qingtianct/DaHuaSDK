/**
 * Copyright (c) 2014~2015, 浙江大华系统工程有限公司 All rights reserved.
 * \file		ibp_error_enum.h
 * \brief		ibp_error_enum
 * \author		24997
 * \date		2016年6月28日
 * \note		eIBP_Err错误码信息
 */
#ifndef _IBP_ERROR_ENUM_H_
#define _IBP_ERROR_ENUM_H_

/**
* @defgroup 错误码
* @{
*/

/**
@brief 错误码信息
@remarks
@see
*/
typedef enum {
	IBP_Err_OK = 200,										///<正确错误码
	
	IBP_Err_Common_Begin = 300,								///<通用错误码开始
	IBP_Err_Common_XML_NULL,								///<xml为空
	IBP_Err_Common_XML_ERR,									///<xml异常
	IBP_Err_Common_No_Buffers,								///<缓存不够
	IBP_Err_Common_SendMsg_Failed,							///<消息发送失败
	IBP_Err_Common_PARAM_ERR,								///<参数错误
	IBP_Err_Common_Device_Offline,							///<设备掉线
	IBP_Err_Common_IpPort_Dup,								///<dvr设备的IP,port重复
	IBP_Err_Common_NETSDK,									///<netsdk错误
	IBP_Err_NO_RIGHTS,										///<没有操作权限
	IBP_Err_CANNOT_FIND_DEVICE,								///<没有找到请求的设备
	IBP_Err_CANNOT_FIND_USER,								///<由SessionId没有找到UserId
	IBP_Err_Common_IbpProtocol_NULL,						///<协议为空
	IBP_Err_Common_Socket_Err,								///<socket建立异常
	IBP_Err_SerialPort_InUse,								///<串行口正在被使用
	IBP_Err_SerialPort_OpenFailed,							///<串口打开失败

	IBP_Err_CANNOT_SUPPORT_DVR_TYPE,					    ///<不支持的DVR类型

	
	IBP_Err_DB_Begin = 400,									///<数据库错误码开始
	IBP_Err_DBConnect_Fail = 400,							///<数据库的错误码放在一起，连接错误
	IBP_Err_DBOperate_Fail,									///<数据库增删改错误
	IBP_Err_DBQuery_Fail,									///<数据库查询错误
	IBP_Err_DBInsert_Fail,									///<数据库insert错误
	IBP_Err_DBDelete_Fail,									///<数据库delete错误
	IBP_Err_DBSelect_Fail,									///<数据库select错误
	IBP_Err_DBUpdate_Fail,									///<数据库update错误
	IBP_Err_DBOperate_Fail_RecordNotExists,					///<数据库操作的记录不存在
	IBP_Err_DB_End = 499,									///<数据库错误码结束
	
	IBP_ERR_COMMON_OUTPROCESS_Begin = 900,					///<关键错误码分开处理开始
	IBP_ERR_COMMON_OUTPROCESS_NO_SESSION = 900,				///<outprocess找不到句柄
	IBP_ERR_COMMON_OUTPROCESS_SERVICE_UNAVAILABLE,			///<outprocess服务不可用
	IBP_ERR_COMMON_OUTPROCESS_NOT_FOUND_BYSEQ,				///<没有找到peer
	IBP_ERR_COMMON_OUTPROCESS_PROTOCOL_NULL,				///<协议为空
	IBP_ERR_COMMON_OUTPROCESS_End = 909,					///<关键错误码分开处理结束
	
	IBP_ERR_COMMON_LOADBALANCE_CMU_ALEADY_LOGIN = 910,		///<负载均衡CMU已经登录
	IBP_ERR_COMMON_LOADBALANCE_NOT_MASTER,					///<负载均衡无master
	IBP_Err_Common_End = 999,								///<通用错误结束
	
	IBP_Err_CMU_Begin = 1000,								///<CMU开始
	IBP_Err_Nothing_Found,									///<未找到
	IBP_Err_KEY_CONFLICT,									///<关键字冲突
	IBP_Err_USERNAME_CONFLICT,								///<用户名冲突
	IBP_Err_USER_NOT_LOGON,									///<用户未登录
	IBP_Err_USERNAME_NONEXISTENT,							///<用户名不存在
	IBP_Err_ERROR_PASSWORD,									///<密码错误
	IBP_Err_USER_LOCKED,									///<用户锁定
	IBP_Err_USER_OUT_OF_DATE,								///<用户过期
	IBP_Err_USER_NOT_IN_DATE,								///<用户不在使用期内
	IBP_Err_USER_MULT_LOGIN,								///<用户重复登录
	IBP_Err_USER_ADMIN_ONLINE_OVER,							///<admin在线超过限制
	IBP_Err_USER_USER_ONLINE_OVER,							///<用户在线超过限制
	IBP_Err_USER_MAX,										///<用户达到最大值	
	IBP_Err_EXT_PASSWORD_ERR,								///<话机密码不能为空
	IBP_Err_EXT_NUMBER_DUPLICATE,							///<话机号码与已有号码或备号重复
	IBP_Err_EXT_ATTENDANT_DUPLICATE,						///<话机号码与总机号码重复
	IBP_Err_EXT_EMPTY_ERR,									///<分机号码为空
	IBP_Err_ORG_DEL_HAVSUBORG,								///<挂有组织，不能删除该组织
	IBP_Err_ORG_DEL_HAVSUBDEV,								///<挂有设备，不能删除该组织
	IBP_Err_ORG_DEL_HAVUSER,								///<挂有用户，不能删除该组织
	IBP_Err_ORG_DEL_HAVDOMAIN,								///<挂有域，不能删除该组织
	IBP_Err_DOMAIN_ID_ERR,									///<DomainId 错误
	IBP_Err_CMU_ORG_NOT_EXIST,								///<组织不存在
	IBP_Err_CMU_SAME_CODE_DEV_NOT_EXIST,					///<不存在该编码设备
	IBP_Err_CMU_SAME_CODE_DEV_EXIST,						///<已存在该编码设备
	IBP_Err_CMU_OLD_DEV_NOT_EXIST,							///<原设备不存在
	IBP_Err_CMU_PARENT_DEV_NOT_EXIST,						///<父设备不存在
	IBP_Err_CMU_Not_Match_Database,							///<Cmu和数据库版本不匹配
	IBP_Err_ORG_DEL_HAVROLE,								///<挂有角色，不能删除该组织
	IBP_Err_USER_BIND_OTHER_DEVICE,							///<用户绑定了其他设备
	IBP_Err_ERROR_PASSWORD_FOR_5,							///<密码错误5次，24小时以后再试
	IBP_Err_USER_MULT_LOGIN_FROM,							///<终端重复登录
	IBP_Err_USER_MULT_LOGIN_NUMBER,							///<终端绑定的号码重复登录
	IBP_Err_CONTACT_NUM_DUPLICATE,							///<通讯录号码重复
	IBP_Err_BIND_GROUP_NUM_DUPLICATE,						///<绑定的组号码重复
	IBP_Err_BIND_GROUP_NUM_NOT_ENOUGH,						///<绑定的组号码不够用
	IBP_Err_ARSSERVER_OFFLINE,								///<ars服务离线
	IBP_Err_NOT_CONNECT_FROM_UAC,							///<APP需要从UAC进行连接登陆
	IBP_Err_VERSION_ID_DUPLICATE,							///<版本号重复
	IBP_Err_EXT_GATEWAY_DUPLICATE,							///<话机号码与网关号码重复
	IBP_Err_LDAP_AUTHENTICATION_ERR,						///<ldap鉴权失败
	IBP_Err_LDAP_USER_NOT_IN_DOMAIN,						///<用户不在当前域中
	IBP_Err_PARTIAL_SUCCESS,								///<部分操作成功
	IBP_Err_BIND_NUM_DUPLICATE,								///<号码重复绑定
	IBP_ERR_IEMI_ERR,										///<IEMI值为0,初始化
	IBP_Err_CMU_End = 1099,									///<CMU结束
	
	IBP_Err_VTDU_Begin = 1100,								///<VTDU结束
	IBP_Err_Start_Unfinished,								///<VTDU启动未完成
	IBP_Err_Not_Find_VRU,									///<未发现vru
	IBP_Err_No_Enough_Capability,							///<没有足够的能力
	IBP_Err_Device_Not_Support,								///<设备不支持
	IBP_Err_Cannot_Find_Device,								///<查找不到设备
	IBP_Err_Not_Find_Slave,									///<找不到slave
	IBP_Err_SendMsg_MasterToSlave,							///<master向slave发送消息失败
	IBP_Err_SendMsg_MasterToDomain,							///<master向其他域发送消息失败
	IBP_Err_Device_Offline,									///<设备掉线
	IBP_Err_DllName_Empty,									///<dll名为空
	IBP_Err_Record_Seek_Format,								///<录像拖动格式错误
	IBP_Err_Cascade_Server_Offline,							///<级联服务rtsp链接掉线
	IBP_Err_Channel_Used_In_Talking,						///<语音对讲-通道处于使用状态，用于语音限制
	IBP_Err_Channel_Used_In_Playing,						///<录像回放-通道处于使用状态，用于录像回放限制
	IBP_Err_RtspToken_Invalid,								///<rtsp token无效
	IBP_Err_Channel_In_Closing,								///<通道处于正在关闭状态
	IBP_Err_Not_Find_Channel,								///<未找到通道
	IBP_Err_Rtsp_Disconnect,								///<rtsp连接断开
	IBP_Err_Cascade_Connect,								///<连接级联服务失败
	IBP_Err_No_Port_For_Use,								///<没有端口可使用
	IBP_Err_Play_No_Setup,									///<发送rtsp play前未发送setup消息
	IBP_Err_RTP_Build,										///<码流传输网络建立失败
	IBP_Err_Add_Node_Into_SendList,							///<加入发送列表失败
	IBP_Err_Delete_Node_Failed,								///<删除node失败
	IBP_Err_Record_Download_Finished,						///<录像下载完成
	IBP_Err_No_Record_Files,								///<没有录像文件
	IBP_Err_Receiver_Net_Build,								///<码流接收器网络建立失败
	IBP_Err_SS_Open_File_Failed,							///<ss打开文件失败
	IBP_Err_Msg_Save_Timeout,								///<消息保存超时
	IBP_Err_Not_Find_PlayInfo,								///<找不到播放信息
	IBP_Err_Red5_Connect,									///<连接red5失败
	IBP_Err_Query_UserId_Failed,							///<查询用户ID失败
	IBP_Err_Get_ChannelIndex_Failed,						///<获取通道索引失败
	IBP_Err_Not_Find_USB_Proxy,								///<获取usb代理服务失败
	IBP_Err_Red5_Connech_Already,							///<和red5的连接已经存在
	IBP_Err_Notfound_Startvideo_Request,					///<没有找到请求消息
	IBP_Err_Notfound_Active_Url,							///<没有找到有效的URL
	IBP_Err_Rtcp_Timeout,									///<RTCP超时
	IBP_Err_Not_Find_Source_Msg,							///<找不到原始消息
	IBP_Err_Msg_Is_Not_Fit,									///<不合适的消息
	IBP_Err_User_Right_Alter,								///<用户权限修改，无该设备视频权限
	IBP_Err_VTDU_End = 1199,								///<VTDU结束
	
	IBP_Err_DMU_Begin = 1200,								///<DMU开始
	IBP_Err_DEVICE_OFFLINE,									///<操作的设备离线
	IBP_Err_PTZCONTROL_BYSENIOR,							///<高级用户正在云台控制
	IBP_Err_PTZCONTROL_ASSENIOR,							///<抢占低级用户的云台控制权
	IBP_Err_PTZCONTROL_LOCKBYOTHER,							///<云台被其他用户锁定
	IBP_Err_PTZCONTROL_NOTLOCK,								///<云台没有锁定
	IBP_Err_SERVICE_UNAVAILABLE,							///<当前DMU服务不可用
	IBP_Err_MASTER_SENDTO_SLAVE,							///<Master向Slave发送失败
	IBP_Err_UPMASTER_SENDTO_UPMASTER,						///<UpMaster向LowMaster发送失败
	IBP_Err_UNKNOWMODLE,									///<DMU变成Unknown
	IBP_Err_LOGIN_SAMEIPPORT,								///<重复登录设备
	IBP_Err_LOGIN_DEVICE_FAIL,								///<登录设备失败
	IBP_Err_SCS_OPT_FAILURE,								///<动环操作失败
	IBP_Err_NOT_FIND_DEVID_BY_DOMCODE,						///<根据DomCode，没有找到DevId
	IBP_Err_CANNOT_MODIFY_PREPOINT,							///<不能修改预置位，因为关联一次设备
	IBP_Err_FETCH_GRAPHY_BUSY,								///<正在抓图，请稍后再试
	IBP_Err_FETCH_GRAPHY_UNKNOWN_ERROR,						///<抓图未知错误
	IBP_Err_FETCH_GRAPHY_DEVICE_OFF,						///<抓图过程设备断线
	IBP_Err_PTZCONTROL_LOCKBYSELF,							///<云台已经被自己锁定
	IBP_Err_DMU_OTHERQUERYING,								///<其他用户正查询
	IBP_Err_CANNOT_SUPPORT_DECORDER_TYPE,                   ///<不支持的解码器类型
	IBP_Err_PASSWORD_DUPLICATE,                             ///<密码重复
	IBP_Err_TERMINAL_EXIST_UNDER_ORG,						///<组织下面有终端不能删除组织

	IBP_ERR_ADAPTER_SDK_OPTTASK_FAILED,						///<操作广播系统任务失败
	IBP_ERR_ADAPTER_SDK_MODIFYTERMINAL_FAILED,				///<修改广播系统终端信息失败
	IBP_ERR_ADAPTER_SDK_UPDATE_TERMINAL_FAILED,				///<查询广播系统终端信息失败（获取主机终端信息新增）
	IBP_ERR_ADAPTER_SDK_QUERY_CURRENTFILE,					///<查询广播当前播放文件失败

	IBP_Err_POS_SERVICE_DISC,                               ///<定位服务器未连接 2018.6.28 xmchen add 
	IBP_Err_DMU_End = 1299,									///<DMU结束
	
	IBP_Err_VRU_Begin = 1300,								///<VRU结束
	IBP_Err_NOSLAVE_AVALIABLE,								///<没有Slave可用
	IBP_Err_NOTSUPPORTED,									///<功能不支持
	IBP_Err_DATABASE_FAILED,								///<数据库操作失败
	IBP_Err_PlanData_Empty,									///<计划配置为空
	IBP_Err_VRU_Start_Unfinished,							///<vru启动未完成
	IBP_Err_Not_Find_VTDU,									///<未找到vtdu
	IBP_Err_RtspConnect_Failed,								///<
	IBP_Err_CreateChannel_Failed,							///<
	IBP_Err_RTP_Build_Failed,								///<
	IBP_Err_No_RtpPort_For_Use,								///<
	IBP_Err_Channel_Used_In_Storing,						///<通道处于使用状态，用于存储
	IBP_Err_AddStreamId_Failed,								///<存储时添加流id失败
	IBP_Err_Receive_Data_Timeout,							///<接受码流超时
	IBP_Err_Server_Disconnect,								///<和服务的连接断开
	IBP_Err_Device_Disconnect,								///<设备连接断开
	IBP_Err_Add_CqfsSession_Failed,							///<添加cqfssession失败
	IBP_Err_ReceiveStream_Timeout,							///<接受流超时
	IBP_Err_Right_Alter,									///<权限改变
	IBP_Err_Device_Alter,									///<设备信息改变
	IBP_Err_Synopsis_AddTask_Err,							///<netsdk添加浓缩任务错误
	IBP_Err_Synopsis_SetCallBack_Err,						///<netsdk设置浓缩状态回调错误
	IBP_Err_VRU_DeleteClip_Failded,                         ///<vru删除clip失败
	IBP_Err_VRU_GetDiskFreeSpace_Failded,                   ///<vru获取剩余空间失败
	IBP_Err_VRU_NotOpenOtherDomidVideo,                     ///<vru无法打开其他域视频
	IBP_Err_VRU_StreamId_Delete,                            ///<vru流ID已经被删除
	IBP_Err_VRU_End = 1399,									///<VRU结束
	
	IBP_Err_LKU_Begin = 1400,								///<LKU结束
	IBP_Err_LKU_End = 1499,									///<LKU结束
	
	IBP_Err_LMU_Begin = 1500,								///<LMU结束
	IBP_Err_LMU_QueryUserBindTelePhone_Empty,				///查询组织下用户绑定手机号码结果为空
	IBP_Err_LMU_End = 1599,									///<LMU结束
	
	IBP_Err_UAS_Begin = 1600,								///<UAS错误码开始
	IBP_Err_UAS_Cmu,										///<UAS中CMU模块错误
	IBP_Err_UAS_Dmu_Master,									///<UAS中Dmu Master模块错误
	IBP_Err_UAS_Dmu_Slave,									///<UAS中Dmu Slave模块错误
	IBP_Err_UAS_Vtdu,										///<UAS中Vtdu模块错误
	IBP_Err_UAS_Logic,										///<UAS中逻辑模块错误
	IBP_Err_UAS_Sip,										///<UAS中Sip错误
	IBP_Err_UAS_Rtsp,										///<UAS中Rtsp错误
	IBP_Err_UAS_Pg,											///<UAS中Pg错误
	IBP_Err_UAS_Res,										///<UAS中应答协议错误
	IBP_Err_UAS_Res_Not_Find,								///<UAS收到应答未找到设备
	IBP_Err_UAS_Res_Not_Right,								///<UAS收到应答无设备权限
	IBP_Err_UAS_Res_Login_Fail,								///<UAS收到应答登陆设备失败或设备不在线
	IBP_Err_UAS_Sip_Res_Timeout,							///<UAS中SIP超时未收到应答
	IBP_Err_UAS_Platform,									///<UAS中下级处理返回失败
	IBP_Err_UAS_Cookie_Invalid,								///<UAS中cookie失效
	IBP_Err_UAS_Login,										///<UAS未登录
	IBP_Err_UAS_End = 1699,									///<UAS错误码结束
	
	IBP_Err_UAC_Begin = 1700,								///<UAC错误码开始
	IBP_Err_UAC_End = 1799,									///<UAC错误码结束
	
	IBP_ERR_ADAPTER_BEGIN = 1800,							///<设备适配器开始
	IBP_ERR_ADAPTER_CANNOT_FIND_DEV,						///<没有找到设备对象
	IBP_ERR_ADAPTER_DYNAMICCAST_FAILD,						///<转化错误
	IBP_ERR_ADAPTER_DVR_IPPORT_DUP,							///<DVR IP Port
	IBP_ERR_ADAPTER_DLL_LOAD_FAIL,							///<DLL加载错误
	IBP_ERR_ADAPTER_PARAMTER_ERROR,							///<参数错误
	IBP_ERR_ADAPTER_DEVICE_OFFLINE,							///<设备下线
	IBP_ERR_ADAPTER_START_LISTEN_FAILED,					///<开启主动注册监听失败

	IBP_ERR_ADAPTER_SDK_BEGIN = 1850,						///<适配器SDK开始
	IBP_ERR_ADAPTER_SDK_USER_PASSWORD_ERROR,				///<用户密码错误
	IBP_ERR_ADAPTER_SDK_LOG_TIMEOUT,						///<登陆超时
	IBP_ERR_ADAPTER_SDK_USER_LOCKED,						///<用户锁定
	IBP_ERR_ADAPTER_SDK_ILLEGAL_USER,						///<非法用户
	IBP_ERR_ADAPTER_SDK_RESOURCE_ERROR,						///<资源错误
	IBP_ERR_ADAPTER_SDK_LOGNET_ERROE,						///<网络错误
	IBP_ERR_ADAPTER_SDK_PING_ERROE,							///<PING错误
	IBP_ERR_ADAPTER_SDK_MAX_USERNUM,						///<超过最大用户数量
	IBP_ERR_ADAPTER_SDK_REAL_PLAY,							///<实时视频播放
	IBP_ERR_ADAPTER_SDK_VEDIO_STOP,							///<视频停止
	IBP_ERR_ADAPTER_SDK_REAL_TALK,							///<语音对讲
	IBP_ERR_ADAPTER_SDK_TALK_STOP,							///<对讲停止
	IBP_ERR_ADAPTER_SDK_CHANNEL_USED_IN_PLAYING,			///<该通道用户正在使用
	IBP_ERR_ADAPTER_SDK_RECORD_DOWNLOAD_FINISHED,			///<录像下载完成
	IBP_ERR_ADAPTER_SDK_LOGIN_DEVICE_FAIL,					///<登陆设备失
	IBP_ERR_ADAPTER_SDK_API,								///<API错误
	IBP_ERR_ADAPTER_SDK_API_FAILED,							///<API调用失败
	IBP_ERR_ADAPTER_SDK_CREAT_DEVICE_FAILED,				///<创建设备失败
	IBP_ERR_ADAPTER_SDK_NOW_UNAVAILABLE=1869,				///<当前无法执行
	IBP_ERR_ADAPTER_END = 1899,								///<设备适配器结束
	
	IBP_Err_MCU_Begin = 1900,								///<MCU开始
	IBP_Err_MCU_UNKNOWMODEL,								///<服务模式为Unknown
	IBP_Err_MCU_NOT_MASTER,									///<不是master
	IBP_Err_MCU_INVALID_CONNECTION,							///<无效连接
	IBP_Err_MCU_INVALID_PARAM,								///<无效参数
	IBP_Err_MCU_NO_USER_ID,									///<用户id不存在
	IBP_Err_MCU_NO_IMSDINFO,								///<用户关联的IMDS信息找不到
	IBP_Err_MCU_KEY_CONFLICT,								///<关键字冲突
	IBP_Err_MCU_PASSWORD_INVALID,							///<密码错误
	IBP_Err_MCU_LOGIN_ALREADY,								///<已经登录
	IBP_Err_MCU_MEETING_ID_INVALID,							///<会议室id无效
	IBP_Err_MCU_NOT_LOGIN,									///<没有登录
	IBP_Err_MCU_MEETING_LOCKED,								///<会议室被锁定
	IBP_Err_MCU_NO_SIP_SERVER,								///<没有sip服务器
	IBP_Err_MCU_SIP_INIT,									///<sip初始化失败
	IBP_Err_MCU_SIP_REGISTER,								///<sip 注册失败
	IBP_Err_MCU_NOT_MAINSPEAKER,							///<不是主讲人
	IBP_Err_MCU_USER_OFFLINE,								///<用户不在线
	IBP_Err_MCU_SESSION_INVALID,							///<无效session
	IBP_Err_MCU_NO_CALLERNUMBER,							///<无虚拟主叫号码可用
	IBP_Err_MCU_HOOK_ERR,									///<摘机错误
	IBP_Err_MCU_MAX_USER_LIMIT,								///<达到用户最大数上限
	IBP_Err_MCU_IMDS_OFFLINE,								///<IMDS服务离线
	IBP_Err_MCU_MEET_NOT_MODIFY,							///<会议进行中不能修改
	IBP_Err_MCU_EMERGENCY_MEETING_EXIST,					///<已经存在应急会议
	IBP_Err_MCU_PHONE_IS_CALLING,							///<电话正在拨打中
	IBP_Err_MCU_PHONE_STATE_WRONG,							///<电话状态错误
	IBP_Err_MCU_FEATURE_NOT_SUPPORTED,						///<不支持该功能
	IBP_Err_MCU_COLLECTION_IS_EXISTED,						///<联系人信息已经被收藏
	IBP_Err_MCU_ROOM_IS_NOT_EXISTED,						///<会议室不存在
	IBP_Err_MCU_ADGU_OFFLINE,								///<ADGU服务离线
	IBP_Err_MCU_MEMBER_IS_IN_THE_MEETING,					///<已经在会议室内
	IBP_Err_MCU_DOMAIN_ERROR,								///<域错误
	IBP_Err_MCU_MEMBER_IS_IN_OTHER_MEETING,					///<用户已经在其他会议室内
	IBP_Err_MCU_MEETING_IS_NOT_EXISTED,						///<会议不存在
	IBP_Err_MCU_MAIN_SPEAKER_IS_NOT_EXISTED,				///<主讲人不存在
	IBP_Err_MCU_MEETING_ROOM_EXIST,							///<会议室已经存在
	IBP_ERR_MCU_PHONE_HANGUP_TIMELATE,						///话机挂断或呼叫超时
	IBP_Err_MCU_End = 1999,									///<MCU结束
	
	IBP_Err_IIS_Begin = 2000,								///< IIS 开始
	IBP_Err_IIS_NOT_MASTER,									///<不是master
	IBP_Err_IIS_PlanNotExist,								///<计划不存在
	IBP_Err_IIS_UnknownOpt,									///<未知操作
	IBP_Err_IIS_AddTaskFail,								///<添加任务失败
	IBP_Err_IIS_UpdateTaskFail,								///<任务配置更新失败
	IBP_Err_IIS_DeleteTaskFail,								///<任务删除失败
	IBP_Err_IIS_AddPointFail,								///<添加巡检点失败
	IBP_Err_IIS_UpdatePointFail,							///<更新巡检点失败
	IBP_Err_IIS_DeletePointFail,							///<删除巡检点失败
	IBP_Err_IIS_AddTimeSchduleFail,							///<添加时间模板失败
	IBP_Err_IIS_UpdateTimeSchduleFail,						///<更新时间模板失败
	IBP_Err_IIS_DeleteTimeSchduleFail,						///<删除时间模板失败
	IBP_Err_IIS_QueryTaskFail,								///<查询任务失败
	IBP_Err_IIS_QueryPointFail,								///<查询巡检点失败
	IBP_Err_IIS_QueryTimeTemplateFail,						///<查询时间模板失败
	IBP_Err_IIS_CreatePlayFailed,							///<创建播放Instance失败
	IBP_Err_IIS_SnapshotFailed,								///<抓图失败
	IBP_Err_IIS_ExcutePlanFailed,							///<计划执行成功和失败
	IBP_Err_IIS_PlanStarted,								///<计划已经开始
	IBP_Err_IIS_PlanStopped,								///<计划已经结束
	IBP_Err_IIS_CalIrIndexError,							///<红外指标计算失败
	IBP_Err_IIS_CalIrTempDiffError,							///<红外温差计算失败
	IBP_Err_IIS_PlanSubscribeFailed,						///<计划订阅失败
	IBP_Err_IIS_NoAvailableSlaver,							///<没有可用的从机
	IBP_Err_IIS_PanelParam1Error,							///<仪表分析-第一个参数错误
	IBP_Err_IIS_PanelParam2Error,							///<仪表分析-第二个参数错误
	IBP_Err_IIS_IVPEError,									///<仪表分析库分析错误
	IBP_Err_IIS_End = 2099,									///<IIS结束
	
	IBP_Err_FS_Begin = 2100,								///<FS 开始
	IBP_Err_FS_NOT_MASTER,									///<不是master
	IBP_Err_FS_End = 2199,									///<FS结束
	
	IBP_Err_ADGU_Begin = 2200,								///<ADGU开始
	IBP_Err_ADGU_UNKNOWMODEL,								///<服务模式为Unknown
	IBP_Err_ADGU_NOT_MASTER,								///<不是master
	IBP_Err_ADGU_INVALID_CONNECTION,						///<无效连接
	IBP_Err_ADGU_INVALID_PARAM,								///<无效参数
	IBP_Err_ADGU_NO_USER_ID,								///<用户id不存在
	IBP_Err_ADGU_KEY_CONFLICT,								///<关键字冲突
	IBP_Err_ADGU_RTSP,										///<ADGU中Rtsp错误
	IBP_Err_ADGU_IPPORT,									///<ADGU地址错误
	IBP_Err_ADGU_ID_MAPPING,								///<ADGU设备id映射错误
	IBP_Err_ADGU_VIDEO_IS_OPEN,								///<ADGU中视频已打开
	IBP_Err_ADGU_INVITE_FAILED,								///<ADGU  INVITE请求失败
	IBP_Err_ADGU_VIDEO_HAS_BEEN_CLOSED,						///<ADGU视频已经被关闭
	IBP_Err_ADGU_BYE_FAILED,								///<ADGU  BYE请求失败
	IBP_Err_ADGU_CAN_NOT_GET_RTP_INFO,						///<ADGU获取RTP信息失败
	IBP_Err_ADGU_MEDIA_SESSION_IS_NULL,						///<ADGU媒体信息为空
	IBP_Err_ADGU_SEND_MSG_CMU,								///<ADGU 发送消息给CMU失败
	IBP_Err_ADGU_IPC_CALLED,								///<已在通话
	IBP_Err_ADGU_IPC_GET_DEV,								///<获取设备信息失败
	IBP_Err_ADGU_IPC_GET_DEV_BY_CHNL,						///<根据通道获取设备信息失败
	IBP_Err_ADGU_IPC_LOGIN_FAILED,							///<登录设备失败
	IBP_Err_ADGU_IPC_NOT_FIND_DEV,							///<找不到设备信息
	IBP_Err_ADGU_IPC_LOGIN_NO_DEV,							///<找不到已经登录的设备
	IBP_Err_ADGU_IPC_ADD_TRANSFER,							///<添加转发节点失败
	IBP_Err_ADGU_AUDIO_CALL,								///<语音呼叫不能打开视频
	IBP_Err_ADGU_IPC_PLAY,									///<请求对讲失败
	IBP_Err_ADGU_Chnl_Unsupport,							///<该通道不支持
	IBP_Err_ADGU_End = 2299,								///<ADGU结束
	
	IBP_Err_VMU_Begin = 2300,								///<VMU开始
	IBP_Err_VMU_UNKNOWMODEL,								///<服务模式为Unknown
	IBP_Err_VMU_NOT_MASTER,									///<不是master
	IBP_Err_VMU_INVALID_CONNECTION,							///<无效连接
	IBP_Err_VMU_INVALID_PARAM,								///<无效参数
	IBP_Err_VMU_KEY_CONFLICT,								///<关键字冲突
	IBP_Err_VMU_RTSP,										///<VMU中Rtsp错误
	IBP_Err_VMU_IPPORT,										///<VMU地址错误
	IBP_Err_VMU_SERVER_NOT_REGISTER,						///<VMU没有注册
	IBP_Err_VMU_NOT_FOUND_NVD,								///<没有找到NVD
	IBP_Err_VMU_ENCODE_PDU,									///<
	IBP_Err_VMU_DECODE_PDU,									///<
	IBP_Err_VMU_SERVER_RETURN_ERR,							///<VMU服务返回失败
	IBP_Err_VMU_End = 2399,									///<VMU结束
	
	IBP_Err_LCU_Begin = 2400,								///<LCU开始
	IBP_Err_LCU_UNKNOWMODEL,								///<服务模式为Unknown
	IBP_Err_LCU_NOT_MASTER,									///<不是master
	IBP_Err_LCU_INVALID_CONNECTION,							///<无效连接
	IBP_Err_LCU_INVALID_PARAM,								///<无效参数
	IBP_Err_LCU_ENCODE_PDU,									///<
	IBP_Err_LCU_DECODE_PDU,									///<
	IBP_Err_LCU_USER_OFFLINE,								///<用户下线
	IBP_Err_LCU_GROUP_UNEXIST,								///<组不存在
	IBP_Err_LCU_GROUPID_REPEAT,								///<组id重复
	IBP_Err_LCU_GROUPMEMBER_UNEXIST,						///<组成员不存在
	IBP_Err_LCU_USER_UNEXIST,								///<用户不存在
	IBP_Err_LCU_USER_EXISTED,								///<用户已经存在
	IBP_Err_LCU_DEVICE_UNEXIST,								///<设备不存在
	IBP_Err_LCU_DEVICE_EXISTED,								///<设备已经存在
	IBP_Err_LCU_DELMEMBER_FAIL,					        	///<删除成员失败
	IBP_Err_LCU_NOAUTHORITY,					        	///<无操作权限
	IBP_Err_LCU_MKDIR_FAIL,					        		///<创建目录失败
	IBP_Err_LCU_DWFILE_FAIL,					        	///<下载文件失败
	IBP_Err_LCU_FILE_UNEXIT,					        	///<文件不存在
	IBP_Err_LCU_FILEOPEN_FAIL,					        	///<文件打开失败
	IBP_Err_LCU_GROUP_BUSY,					        		///<群组正在开会
	IBP_Err_LCU_OPTROOM_FAIL,					        	///<增删改会议室失败
	IBP_Err_LCU_AUDIOROOM_UNEXIST,					        ///<会议室不存在
	IBP_Err_LCU_EQUIPMENT_UNSUPPORT,					    ///<设备不支持
	IBP_Err_LCU_ADDROOM_FAIL,								 ///<加入会议室失败
	IBP_Err_LCU_BUSY,								        ///<用户正在处理其他消息
	IBP_Err_LCU_FILETYPE_ERR,								///<文件格式不对
	IBP_Err_LCU_USER_NOT_INMEETING,							///<用户不在会议室

	IBP_Err_LCU_TASK_UNDONE,								///<有任务没有完成
	IBP_Err_LCU_ALARM_REPEART,								///<有告警重复
	IBP_Err_LCU_USER_NOT_IN_GROUP,							///<用户不在群
	IBP_Err_LCU_ALARM_UNEXIST,								///<有告警不存在
	IBP_Err_LCU_CASE_EXISTED,								///<案件重复
	IBP_Err_LCU_Call_Fail,									///<呼叫失败
	IBP_Err_LCU_Call_Unaccept,								///<拒绝呼叫
	IBP_Err_LCU_Write_Case,									///<增加案件失败
	IBP_Err_LCU_Case_Unexisted,								///<案件不存在
	IBP_Err_LCU_THIS_DEVICE_IS_EXCUTING_CASE,				///<已经在执行该设备的任务
	IBP_Err_LCU_THIS_DEVICE_IS_NOT_EXCUTING_CASE,			///<没有执行该设备的任务
	IBP_Err_LCU_THE_ALARM_HAVE_CASE,						///<告警已经产生案件
	IBP_Err_LCU_DEV_OPT_RIGHT_OVERTIME,						///<视频分享的临时权限已过期
	IBP_Err_LCU_No_ALARM,									///<没有告警信息
	IBP_Err_LCU_CASEID_NULL,								///<案件id为空
	IBP_Err_LCU_CHANGE_CREATER_FAILED,						///<修改案件接警人信息失败
	IBP_Err_LCU_GET_RELATEDALARM_FAILED,					///<取得案件关联告警信息失败
	IBP_Err_LCU_RELATEDALARM_NOEXIST,					    ///<案件关联告警信息为0
	IBP_Err_LCU_CHANGE_REPORTER_FAILED,						///<修改案件报警人信息失败
	IBP_Err_LCU_TASK_RECIVER_INVALID,						///<任务接收者非法
	IBP_Err_LCU_CHANGE_EVENT_FAILED,						///<修改案件事件信息失败

	IBP_Err_LCU_End = 2499,									///<LCU结束

	IBP_Err_License_Begin = 2500,							///<License开始
	IBP_Err_License_DevTypeNotSupported,					///<License不支持该设备类型
	IBP_Err_License_ManufactureNotSupported,				///<License不支持该厂商类型
	IBP_Err_License_UserTypeNotSupported,					///<License不支持该用户类型
	IBP_Err_License_DevNumberNotSupported,					///<该类型设备数量超出License限制
	IBP_Err_License_UserNumberNotSupported,					///<该类型用户数量超出License限制
	IBP_LICENSE_DEVADD_DENY,								///<拒绝添加设备
	IBP_LICENSE_DEVTYPE_DENY,								///<拒绝添加该设备类型
	IBP_LICENSE_ACCEPT_OVER,								///<license接收能力超过
	IBP_Err_License_RunTimeError,							///<运行时间超出License限制
	IBP_Err_License_End = 2699,								///<License结束

	IBP_Err_Cmm_Begin = 2700,								///<Cmm开始
	IBP_Err_Cmm_Not_Master = 2701,							///<Cmm不是master
	IBP_Err_Cmm_End = 2799,									///<Cmm结束

	IBP_Err_OMU_Begin = 2800,									///<OMU开始
	IBP_Err_OMU_NOT_MASTER,									///<不是master
	IBP_Err_OMU_End = 2999,									///<OMU结束

	IBP_Err_DTCU_Begin = 3000,								///<DTCU开始
	IBP_Err_DTCU_UNKNOWMODEL,								///<服务模式为Unknown
	IBP_Err_DTCU_NOT_MASTER,								///<不是master
	IBP_Err_DTCU_End = 3199,								///<DTCU结束

	IBP_Err_SDK_Begin = 10000,								///<SDK开始
	IBP_Err_SDK_Com_Begin = 10000,							///<SDK通用开始
	IBP_Err_SDK_Com_Timeout = 10000,						///<超时
	IBP_Err_SDK_Com_NotFound_OriReq,						///<没有找到原始请求消息
	IBP_Err_SDK_Com_ReqRes_NotSeq,							///<请求和回复命令对不起来
	IBP_Err_SDK_Com_Res_NULL,								///<回复消息为空
	IBP_Err_SDK_Com_LenOver,								///<长度不够
	IBP_Err_SDK_Manager_Failed,								///<SDK manager 初始化失败
	IBP_Err_SDK_Thread_Failed,								///<SDK 启动线程失败
	IBP_Err_SDK_UserCheck_Failed,							///<用户密码校验失败
	IBP_Err_SDK_Response_Null,								///<返回消息体为空
	IBP_Err_SDK_ConnectServer_Error,						///<SDK连接服务错误
	IBP_Err_SDK_NO_INIT,									///<没有初始化
	IBP_Err_SDK_Notify,										///<Notify失败，安卓下系统化恢复中
	IBP_Err_SDK_NotTcpMedia,								///<不为TCP码流
	IBP_Err_SDK_GetTcpBuffFail,								///<获取TCP码流缓存区堆积计数失败
	IBP_Err_SDK_Com_End	= 10999,							///<SDK通用结束
	
	IBP_Err_SDK_CMU_Begin = 11000,							///<CMU开始
	IBP_Err_SDK_CMU_End = 11099,							///<CMU结束
	
	IBP_Err_SDK_VTDU_Begin = 11100,							///<VTDU开始
	IBP_Err_SDK_Not_Connect,								///<未连接vtdu
	IBP_Err_SDK_Not_Find_Session,							///<未找到session
	IBP_Err_SDK_No_RtspConnect,								///<未建立rtsp连接
	IBP_Err_SDK_No_RtspSetup,								///<未进行setup流程
	IBP_Err_SDK_No_RtspPlay,								///<未进行play流程
	IBP_Err_SDK_RTP_Connect_Failed,							///<码流接受对端建立失败
	IBP_Err_SDK_VTDU_End = 11199,							///<VTDU结束
	
	IBP_Err_SDK_DMU_Begin = 11200,							///<DMU开始
	IBP_Err_Has_User_RevAlarm,                              //已经有用户接警
	IBP_Err_SDK_DMU_End = 11299,							///<DMU结束
	
	IBP_Err_SDK_VRU_Begin = 11300,							///<VRU开始
	IBP_Err_SDK_RtspConnect_Failed,							///<
	IBP_Err_SDK_VRU_End = 11399,							///<VRU结束
	
	IBP_Err_SDK_LKU_Begin = 11400,							///<LKU开始
	IBP_Err_SDK_LKU_End = 11499,							///<LKU结束
	
	IBP_Err_SDK_LMU_Begin = 11500,							///<LMU开始
	IBP_Err_SDK_LMU_End = 11599,							///<LMU结束
	
	IBP_Err_SDK_FS_Begin = 11600,							///<FS开始
	IBP_Err_SDK_Generate_GUID_Failed,						///<生成文件GUID失败
	IBP_Err_SDK_File_GUID_Invalid,							///<文件GUID无效
	IBP_Err_SDK_FileInfo_Wrong,								///<文件信息填写错误
	IBP_Err_SDK_FilePath_Wrong,								///<文件路径填写填写错误
	IBP_Err_SDK_File_Open_Failed,							///<文件打开失败
	IBP_Err_SDK_File_Exist,									///<同名文件已存在
	IBP_Err_SDK_File_Not_Exist,								///<上传/下载文件不存在
	IBP_Err_SDK_File_Size_Limited,							///<上传文件太大（超过2G）
	IBP_Err_SDK_Disk_Full,									///<本地/服务器磁盘空间已满
	IBP_Err_SDK_File_In_Use,								///<文件正在使用,正在上传或正在下载
	IBP_Err_SDK_FileInfo_Lost,								///<内存中文件信息丢失,不能写入数据库
	IBP_Err_SDK_Logic_Wrong,								///<逻辑错误，需要修改
	IBP_Err_SDK_New_Buf_Failed,								///<申请空间失败
	IBP_Err_SDK_Write_Database_Failed,						///<写入数据库失败
	IBP_Err_SDK_File_Del_Failed,							///<文件删除失败
	IBP_Err_SDK_File_Downloading,							///<文件正在下载中
	IBP_Err_SDK_Make_Dir_Failed,							///<创建文件夹失败
	IBP_Err_SDK_FS_End = 11799,								///<FS结束
	
	IBP_Err_SDK_ADAPTER_Begin = 11800,						///<SDK ADAPATER 开始
	IBP_Err_SDK_ADAPTER_SnapshotFailed,						///<抓图失败
	IBP_Err_SDK_ADAPTER_PacketDataFailed,					///<组包失败
	IBP_Err_SDK_ADAPTER_ParseDataFailed,					///<解析失败
	IBP_Err_SDK_ADAPTER_End = 11899,						///<SDK ADAPATER结束
	
	IBP_Err_SDK_CMM_Begin = 11900,							///<SDK CMM 开始
	IBP_Err_SDK_CMM_Is_Not_Connected,						///<CMM没有连接
	IBP_Err_SDK_CMM_No_Function,							///<CMM没有处理方法
	IBP_Err_SDK_CMM_Sys_Code_Conflict,						///<子系统code字段冲突
	IBP_Err_SDK_CMM_End = 11999,							///<SDK CMM结束
	
	IBP_Err_SDK_IMS_Begin = 12000,							///<SDK IMS 开始
	IBP_Err_SDK_IMS_MSG_ERR,								///<IMS消息错误
	IBP_Err_SDK_IMS_End = 12099,							///<SDK IMS结束
	
	IBP_Err_CANNOT_FIND_FUNCTION = 13900,					///<查找不到该函数
	IBP_Err_CANNOT_LOGIN_MORE_PLATFORM,						///<无法登陆更多的平台
	IBP_Err_Not_Find_PlatForm,								///<无法找到该平台
	IBP_Err_PlatForm_OffLine,								///<该平台离线
	IBP_Err_Not_Find_DMU,									///<无法找到DMU
	IBP_Err_Not_Find_IIS,									///<无法找到IIS
	IBP_Err_Not_Find_IMDS,									///<无法找到IMDS
	IBP_Err_Not_Find_FS,									///<无法找到FS
	IBP_Err_Not_Find_LMU,									///<无法找到lmu

	IBP_Err_PLAY_Begin = 14000,								///<SDK播放库部分开始
	IBP_Err_PLAY_LoadLibraryFailed,							///<加载解码库失败
	IBP_Err_PLAY_GetProcAddrFailed,							///<加载解码库函数地址失败
	IBP_Err_PLAY_CannotCreateInvalidChannel,				///<无法创建一个类型为“无效”的频道
	IBP_Err_PLAY_NoneFreePort,								///<创建频道失败（解码库没有空闲的port）
	IBP_Err_PLAY_NoneFreeChannel,							///<申请不到空闲频道
	IBP_Err_PLAY_OutBoundChannel,							///<频道号越界
	IBP_Err_PLAY_ReleaseFreeChannel,						///<无法释放空闲的频道
	IBP_Err_PLAY_CannotOperateFreeChannel,					///<无法操作空闲的频道

	IBP_Err_PLAY_CannotPlayWhenNotStreamType,				///<当前不处于流模式，无法播放
	IBP_Err_PLAY_CannotPlayWhenIsPlaying,					///<当前已正在播放中，无法播放
	IBP_Err_PLAY_CannotPlayWhenNoneWindow,					///<当前还未添加窗口，无法播放
	IBP_Err_PLAY_SetStreamOpenModeFailed,					///<设置流打开的模式时失败
	IBP_Err_PLAY_OpenStreamFailed,							///<打开流失败
	IBP_Err_PLAY_SetDisplayBufFailed,						///<设置显示缓冲失败
	IBP_Err_PLAY_PlayStreamFailed,							///<播放流失败
	
	
	IBP_Err_PLAY_CannotPlayWhenNotFileType,					///<当前不处于文件模式，无法播放
	IBP_Err_PLAY_FileNameIsNull,							///<文件名称为NULL
	IBP_Err_PLAY_OpenFileFailed,							///<打开文件失败
	IBP_Err_PLAY_PlayFileFailed,							///<播放文件失败

	IBP_Err_PLAY_CannotStopWhenIsNotPlaying,				///<当前不在播放中，无法停止播放

	IBP_Err_PLAY_CannotInputWhenNotStreamType,				///<当前不处于流模式，无法送入数据
	IBP_Err_PLAY_CannotInputWhenIsNotPlaying,				///<当前不在播放中，无法送入数据
	IBP_Err_PLAY_InputFailed,								///<送入数据失败

	IBP_Err_PLAY_CannotSetDecodeWhenAudioRecording,			///<录音采集模式下，无法设置解码模式
	IBP_Err_PLAY_CannotSetDecodeWhenNotStreamType,			///<当前不处于流模式，无法设置解码模式
	IBP_Err_PLAY_CannotSetDecodeWhenIsNotPlaying,			///<当前不在播放中，无法设置解码模式
	IBP_Err_PLAY_SetDecodeFailed,							///<设置解码模式失败
	IBP_Err_PLAY_DoNotSupportHardDecode,					///<你的电脑不支持硬解码

	IBP_Err_PLAY_CannotGetDecodeWhenAudioRecording,			///<录音采集模式下，无法获取解码模式
	IBP_Err_PLAY_CannotGetDecodeWhenNotStreamType,			///<当前不处于流模式，无法获取解码模式

	IBP_Err_PLAY_CannotAddMoreWindow,						///<无法添加更多的窗口
	IBP_Err_PLAY_CannotAddExistenceWindow,					///<无法添加已存在的窗口
	IBP_Err_PLAY_CannotRemoveFirstWindowWhenPlaying,		///<无法删除正在播放的“主”窗口
	IBP_Err_PLAY_CannotRemoveInexistenceWindow,				///<无法删除不存在的窗口

	IBP_Err_PLAY_CannotSnapWhenNotPlaying,					///<当前不在播放中，无法抓图
	IBP_Err_PLAY_CannotSnapWhenHardDecode,					///<当前处于硬解码模式，无法抓图
	IBP_Err_PLAY_GetPictureSizeFailed,						///<获取图片原始尺寸失败
	IBP_Err_PLAY_SnapFailed,								///<抓图失败

	IBP_Err_PLAY_CannotOpenSoundWhenNotPlaying,				///<当前不在播放中，无法打开声音
	IBP_Err_PLAY_OenSoundFailed,							///<打开声音失败
	IBP_Err_PLAY_CannotCloseSoundWhenNotPlaying,			///<当前不在播放中，无法关闭声音
	IBP_Err_PLAY_CloseSoundFailed,							///<关闭声音失败

	IBP_Err_PLAY_CannotGetVolumeWhenNotPlaying,				///<当前不在播放中，无法获取音量值
	IBP_Err_PLAY_GetVolumeFailed,							///<获取音量值失败
	IBP_Err_PLAY_CannotSetVolumeWhenNotPlaying,				///<当前不在播放中，无法设置音量值
	IBP_Err_PLAY_SetVolumeFailed,							///<设置音量值失败

	IBP_Err_PLAY_CannotGetColorWhenNotPlaying,				///<当前不在播放中，无法获取色彩值
	IBP_Err_PLAY_GetColorFailed,							///<获取色彩值失败
	IBP_Err_PLAY_CannotSetColorWhenNotPlaying,				///<当前不在播放中，无法设置色彩值
	IBP_Err_PLAY_SetColorFailed,							///<设置色彩值失败

	IBP_Err_PLAY_CannotPlayControlWhenNotPlayback,			///<当前不在回放模式下，无法进行播放控制
	IBP_Err_PLAY_CannotPlayControlWhenNotPlaying,			///<当前不在播放中，无法行播放控制
	IBP_Err_PLAY_PlayControlFailed,							///<播放控制失败

	IBP_Err_PLAY_CannotSetPositionWhenNotFileType,			///<当前不在文本回放模式下，无法设置播放进度值
	IBP_Err_PLAY_CannotSetPositionWhenNotPlaying,			///<当前不在播放中，无法设置播放进度值
	IBP_Err_PLAY_OutBoundPosition,							///<position值越界
	IBP_Err_PLAY_SetPositionFailed,							///<设置播放进度失败
	IBP_Err_PLAY_CannotGetPositionWhenNotFileType,			///<当前不在文本回放模式下，无法获取播放进度值
	IBP_Err_PLAY_CannotGetPositionWhenNotPlaying,			///<当前不在播放中，无法获取播放进度值
	IBP_Err_PLAY_GetPositionFailed,							///<获取播放进度失败

	IBP_Err_PLAY_CannotGetTotalFrameWhenNotFileType,		///<当前不在文件回放模式下，无法获取文件总帧数
	IBP_Err_PLAY_CannotGetTotalFrameWhenNotPlaying,			///<当前不在播放中，无法获取文件总帧数
	IBP_Err_PLAY_GetTotalFrameFailed,						

	IBP_Err_PLAY_CannotGetCurrentFrameWhenNotFileType,		///<当前不在文件回放模式下，无法获取文件当前帧数
	IBP_Err_PLAY_CannotGetCurrentFrameWhenNotPlaying,		///<当前不在播放中，无法获取文件当前帧数
	IBP_Err_PLAY_GetCurrentFrameFailed,						///<获取文件当前帧数失败
	IBP_Err_PLAY_CannotSetCurrentFrameWhenNotFileType,		///<当前不在文件回放模式下，无法设置文件当前帧数
	IBP_Err_PLAY_CannotSetCurrentFrameWhenNotPlaying,		///<当前不在播放中，无法设置文件当前帧数
	IBP_Err_PLAY_SetCurrentFrameFailed,						///<设置文件当前帧数失败

	IBP_Err_PLAY_CannotGetCurrentTimeWhenNotPlayback,		///<当前不在回放模式下，无法获取当前播放时间
	IBP_Err_PLAY_CannotGetCurrentTimeWhenNotPlaying,		///<当前不在播放中，无法获取当前播放时间
	IBP_Err_PLAY_GetCurrentTimeFailed,						///<获取当前播放时间失败

	IBP_Err_PLAY_CannotGetRemainWhenNotPlayback,			///<当前不在回放模式下，无法获取当前剩余帧数
	IBP_Err_PLAY_CannotGetRemainWhenNotPlaying,				///<当前不在播放中，无法获取当前剩余帧数
	IBP_Err_PLAY_GetRemainFailed,							///<获取当前剩余帧数失败

	IBP_Err_PLAY_CannotGetPictureSizeWhenAudioRecording,	///<当前处于语音采集中，无法获取图片尺寸
	IBP_Err_PLAY_CannotGetPictureSizeWhenNotPlaying,		///<当前不在播放中，无法获取图片尺寸

	IBP_Err_PLAY_CbIsNull,									///<传入的cb为NULL
	IBP_Err_PLAY_SetDrawCallbackFailed,						///<设置显示结束回调函数失败
	IBP_Err_PLAY_SetFileEndCallbackFailed,					///<设置文件结束回调函数失败

	IBP_Err_PLAY_BuffIsNull,								///<传入的buff为NULL
	IBP_Err_PLAY_OutBoundCmd,								///<传入的命令字越界
	IBP_Err_PLAY_DoNotSupportQueryMedia,					///<不支持查询媒体信息
	IBP_Err_PLAY_QueryInfoFailed,							///<查询信息失败

	IBP_Err_PLAY_StartAudioRecordWhenNotAudioRecording,		///<当前不处于语音采集模式，无法开启语音采集
	IBP_Err_PLAY_StartAudioRecordFailed,					///<开启语音采集失败
	IBP_Err_PLAY_StopAudioRecordWhenNotAudioRecording,		///<当前不处于语音采集模式，无法关闭语音采集
	IBP_Err_PLAY_StopAudioRecordFailed,						///<关闭语音采集失败

	IBP_Err_PLAY_UnknownError = 14198,						///<未知错误
	IBP_Err_PLAY_End = 14199,								///<SDK播放库部分结束	
	IBP_Err_SDK_Pcc_Start = 14200,							///<PCC_SDK开始
	IBP_Err_SDK_Pcc_IP_Info = IBP_Err_SDK_Pcc_Start,		///<IP解析失败
	IBP_Err_SDK_Pcc_Media_Node,								///<没有mediaNode可以用
	IBP_Err_SDK_Pcc_Media_Node_Timeout,						///<发送超时
	IBP_Err_SDK_Pcc_Open_Local,								///<打开本地
	IBP_Err_SDK_Pcc_End = 14299,
	
	IBP_Err_SDK_END = 20000,								///<SDK结束

}eIBP_Err;

/** @} */

#endif

/**
 * Copyright (c) 2014, 浙江大华系统工程有限公司 All rights reserved.
 * \file		dmu_sdk.h
 * \brief		dmu_sdk
 * \author		24997
 * \date		2014年12月19日
 * \note		DMU SDK 接口
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
* @defgroup DMU_SDK函数
* @{
*/

#pragma region 通用功能



/**
* @defgroup DMU_SDK系统
* @{
*/

/**
@brief DMU_SDK初始化
@return 
@remarks
@see 
*/
DLIB_API t_int32 DMU_SC_Init();


/**
@brief DMU_SDK初始化,服务或者已经启动applicationBase的程序调用
@return 
@remarks
@see DMU_SC_InitNoApp
*/
DLIB_API t_int32 DMU_SC_InitNoApp();

/**
@brief DMU_SDK初始化,单连接
@return 
@remarks
@see 
*/
DLIB_API t_int32 DMU_SC_InitSingle();

/**
@brief DMU_SDK反初始化
@return 
@remarks
@see 
*/
DLIB_API t_int32 DMU_SC_Cleanup();

/** @} */

/**
* @defgroup DMU_SDK连接服务
* @{
*/

/**
@brief 连接DMU服务
@param [in]  timeout		超时时间
@param [in]  cmusession		CMU登陆句柄
@param [in]  ipinfo		    DMU服务的ip信息
@param [in]  svrdomid		DMU服务的域id
@param [in]  serverid		DMU服务id
@param [out] outxml			返回信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<handle></handle>		连接成功返回的句柄
</root>
@endverbatim
@param [in]  maxlen			信息最大长度
@return 
@remarks
@see 
*/
DLIB_API t_int32 DMU_AC_Connect(t_uint32 cmusession, char* ipinfo, char* svrdomid, t_int32 serverid, char* outxml, t_uint32 maxlen);

/**
@brief 用户认证连接DMU服务
@param [in]  timeout		超时时间
@param [in]  usersession	用户认证
@param [in]  ipinfo		    DMU服务的ip信息
@param [in]  svrdomid		DMU服务的域id
@param [in]  serverid		DMU服务id
@param [out] outxml			返回信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<handle></handle>		连接成功返回的句柄
</root>
@endverbatim
@param [in]  maxlen			信息最大长度
@return 
@remarks
@see 
*/
DLIB_API t_int32 DMU_AC_ConnectNoCmu(t_uint32 usersession, char* ipinfo, char* svrdomid, t_int32 serverid, char* outxml, t_uint32 maxlen);

/**
* @defgroup DMU_SDK同步连接
* @{
*/
/**
@brief 同步连接dmu
@param [in] cmuLoginHandle	cmu验证session
@param [in] timeout			超时时间
@param [in] ipInfo			dmu服务ip信息
@param [in] svrDomId		服务域id
@param [in] svrId			服务id
@param [in] maxLen			xmlOutput长度
@param [out] xmlOutput		xml输出
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
<dmusession>2</dmusession>
</root>
@endverbatim
@return						200 成功,其他详见错误码文档 
@remarks
@see 
*/
DLIB_API t_int32 DMU_SC_Connect(t_uint32 cmuLoginHandle, t_int32 timeout, char *ipInfo, char *svrDomId, t_int32 svrId, char *outxml, t_uint32 maxlen);


/**
@brief 断开DMU服务
@param [in]  session		连接句柄
@return 
@remarks
@see 
*/
DLIB_API t_int32 DMU_SC_Disconn(t_uint32 session);

/** @} */

/**
* @defgroup DMU_SDK回调函数
* @{
*/

/**
@brief 消息回调函数
@param [in] session		连接句柄
@param [in] data		消息数据
@param [in] bufSize	    数据长度
@param [in] pUser		用户自定义数据
@return 
@remarks
@see 
*/
typedef t_int32 (*fIbpDmuMsgCallBack)(t_uint32 session, char *data, t_uint32 bufSize, void* pUser);

/**
@brief 设置消息回调函数
@param [in] session		连接句柄
@param [in] cb			回调函数
@param [in] pUser		用户数据
@return 
@remarks 回调消息示例
@verbatim
服务online消息通知
<?xml version='1.0' encoding='utf-8' ?>
<root version="1.0" unit="DMU" type="onlineNotify" cmd="onlineNotify" sequence="0" length="0">
	<server 
		servername="" 			服务名称
		session="" 				服务句柄
		status="" 				上下线状态
	/>
</root>
@endverbatim
@verbatim
报告master更新通知
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="reportMasterUpdate" sequence="" session="0">
	<domid></domid>				域ID
	<modulename></modulename>	模块名称
</root>
@endverbatim
@verbatim
告警数据通知
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="alarmData" sequence="">
	<item
		domid=""				域ID
		devcode=""				设备代码
		devname=""				设备名称
		subdevcode=""			子设备代码
		name=""					子设备名称
		chncode=""				资源或通道代码
		chnname=""				资源或通道名称
		chnidx=""				资源或通道索引
		type=""					告警类型
		subtype=""				告警子类型
		status=""				状态
		level=""				告警等级 0 无 1 严重 2 重要 3 一般 4 次要 5普通
		alarmtime=""			告警上报时间
		msgtxt=""				消息内容
		val=""					值
		unit=""					单位
		orgpath=""				组织设备路径
		title=""				组织设备路径名
		longitude=""            经度(单位是百万分之度，范围0-360度)
		latitude=""             纬度(单位是百万分之度，范围0-180度)
		phonedomid=""			话机域
		phonecode=""			话机编码
		phonenum=""				话机号码
		phonepass=""			话机密码
	/>
</root>
@endverbatim
@verbatim
实时数据通知
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="realData" sequence="">
	<item
		domid=""				域ID
		devcode=""				设备代码
		subdevcode=""			子设备代码
		chncode=""				通道代码
		chnidx=""				通道索引
		val=""					值
		unit=""					单位
		desc=""					描述
		time=""					时间
		isalarm=""				是否告警
		type=""					告警类型
		level=""				告警等级
		orgpath=""			
		title=""
		phonedomid=""			话机域
		phonecode=""			话机编码
		phonenum=""				话机号码
		phonepass=""			话机密码

		intparam1=""			gps定位星数
		intparam2=""			gps天线状态(true 好，false 坏)
		intparam3=""			gps定位状态(true 定位，false 不定位)
		strparam1=""
		strparam2=""
		strparam3=""
	>
		<expand					    pgs扩展信息
			longitude=""			经度(单位是百万分之度，范围0-360度)
			latitude=""				纬度(单位是百万分之度，范围0-180度)
			height=""				高度(米)
			angle=""				方向角(正北方向为原点，顺时针为正)
			speed=""				速度(单位是海里，speed/1000*1.852公里/小时)
		/>
	</item>
</root>
@endverbatim
@verbatim
修改预置点通知
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="modifyPrepointNotify" sequence="">
	<domid></domid>				域ID
	<devcode></devcode>			设备代码
	<index></index>				预置点号
	<name></name>				名称
	<operate></operate>			操作类型
	<userid></userid>			用户ID
	<username></username>		用户名称
	<level>1</level>			用户级别
	<updatetime></updatetime>	操作时间
</root>
@endverbatim
@verbatim
修改OSD通知
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="modifyOSDNotify" sequence="">
	<opt 
		domid="" 				域ID
		devcode="" 				设备代码
		userid="" 				用户ID
		operate="" 				操作类型
		count=""				操作数量
	>
		<info 
			type="" 			修改类型 1 修改OSD标签 2 修改OSD时间
			pointx="" 			原点X坐标
			pointy="" 			原点Y坐标
			width="" 			宽度
			length="" 			高度
			rgb="" 				RGB值
			alpha="" 			ALPHA值
			title=""			标签内容
		/>
	</opt>
</root>
@endverbatim
@verbatim
云台抢占通知
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="ptzArrange" sequence="">
	<domid></domid>				域ID
	<chncode></chncode>			通道代码
	<userid></userid>			用户ID
	<username>0</username>		用户名 
	<level></level>				用户级别
	<department></department>	部门
	<locktime></locktime>		锁定时间
</root>
@endverbatim
@verbatim
查询局域网设备结果通知
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="searchDevRetNotify" sequence="">
	<devcode>abc</devcode>
	<type>1</type>
	<ip></ip>
	<port>1</port>
	<mac></mac>
</root>
@endverbatim

2018.6.26 xmchen add begin  定位相关回调函数
@verbatim
与定位服务器之间的链路连接状态
<?xml version='1.0' encoding='utf-8' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="onlineNotify" sequence="">
	<domid></domid>				        域ID
	<deviceType></deviceType>		        设备代码
	<terminalCode></terminalCode>		   设备号码
	<linkStatus></linkStatus>              0-断开 1-连接
	<version></version>                    服务软件版本，断开时无效
	<date></date>                          日期，断开时无效
	<userid></userid>                      用户名对应的id，连接时由定位服务器返回，断开时无效
</root>
@endverbatim

@verbatim
定位数据通知
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="posDataNotify" sequence="">
	<domid></domid>				       域ID
	<deviceType></deviceType>		       设备代码
	<linkStatus></linkStatus>             0-断开 1-连接
	<sequence></sequence>                 序列号，在整个系统中是唯一的，规则：由用户ID码(4位10进制数,登录后获得）、UTC日期戳（14位10进制数，格式 yyyymmddhhmmss）和5位唯一的十进制序列号串联而成，如：01992009013011552311111。
	<terminalCode></terminalCode>         终端号码
	<terminalType></terminalType>         通信终端类型，1-海事卫星 2-北斗 3-普适 4-AIS 5-GSM 6-GSM手机号 7-短波 8-超短波 9-RFID 10-雷达目标
	<posType></posType>                   位置类型, 类型较多，具体查看文档表3  
	<utc></utc>                           GPS时间: 自1970-01-01 00:00:00以来的秒数
	<longitude></longitude>               经度，单位: 1/10000分
	<latitude></latitude>                 纬度，单位: 1/10000分
	<course></course>                     航向，单位: 1/10度
	<trueHeading></trueHeading>           船艏向，单位: 1/10度
	<speed></speed>                       速度，单位: 1/10节
	<status></status>                     状态码，0-正常 1-终端故障
	<vdesc></vdesc>                       备注，可填写报警原因，或者其它位置携带的附加信息。
</root>
@endverbatim

@verbatim
短信数据通知
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="DMU" type="Notify" cmd="smsDataNotify" sequence="">
<root>
	<domid></domid>				        域ID
	<deviceType></deviceType>		            设备代码
	<sequence></sequence>                  序列号，在整个系统中是唯一的，规则：由用户 ID码(4位10进制数,登录后获得）、UTC日期戳（14位10进制数，格式 yyyymmddhhmmss）和5位唯一的十进制序列号串联而成，如：01992009013011552311111。
	<terminalCodeSrc></terminalCodeSrc>    通信源终端代码。可以为移动终端通信码或组ID
	<terminalTypeSrc></terminalTypeSrc>    源通信终端类型，1-海事卫星 2-北斗 3-普适 4-AIS 5-GSM 6-GSM手机号 7-短波 8-超短波 9-RFID 10-雷达目标
	<terminalCodeDst></terminalCodeDst>    通信目的终端代码。可以为移动终端通信码或组ID
	<terminalTypeDst></terminalTypeDst>    目的通信终端类型，1-海事卫星 2-北斗 3-普适 4-AIS 5-GSM 6-GSM手机号 7-短波 8-超短波 9-RFID 10-雷达目标
	<msgType></msgType>                    短信类型定义 0-普通消息 1-报警消息
	<utc></utc>                            GPS时间: 自1970-01-01 00:00:00以来的秒数
	<msg></msg>                            消息内容
</root>
@endverbatim
2018.6.26 xmchen add end 定位相关回调函数
@see 
*/
DLIB_API t_int32 DMU_SC_SetDmuMsg(t_uint32 session, fIbpDmuMsgCallBack cb, void* pUser);

/**
@brief 设置回调告警数据缓存配置
@param [in] session		连接句柄
@param [in] num			告警条数(默认设置100条)
@return
@remarks
@see 
*/
DLIB_API t_int32 DMU_SC_SetAlarmDataCfg(t_uint32 session, t_int32 num);

/**
@brief 查询最新回调告警数据
@param [in] session		连接句柄
@param [out] outxml		返回信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<item 
		domid=""			域ID
		devcode=""			设备代码
		devname=""			设备名称
		subdevcode=""		子设备代码
		name=""				子设备名称
		chncode=""			资源或通道代码
		chnname=""			资源或通道名称
		chnidx=""			资源或通道索引
		type=""				告警类型
		subtype=""			告警子类型
		status=""			状态
		level=""			告警等级
		alarmtime=""		告警上报时间
		msgtxt=""			消息内容
		val=""				值
		unit=""				单位
		orgpath=""			组织设备路径
		title=""			组织设备路径名
	/>
</root>
@endverbatim
@param [in]  maxlen		信息最大长度
@return
@remarks
@see 
*/
DLIB_API t_int32 DMU_SC_QueryNewAlarmData(t_uint32 session, char *outxml, t_uint32 maxlen);

/**
@brief 设置回调非设备上下线的告警消息
@param [in] session		连接句柄
@param [in] flag		回调标识 0 默认不回调 1 回调
@return
@remarks 如果想实时回调告警消息，请调用此接口
@see 
*/
DLIB_API t_int32 DMU_SC_OpenCbAlarmData(t_uint32 session, t_int32 flag);

/** @} */

/**
* @defgroup DMU_SDK告警订阅
* @{
*/

/**
@brief 设置订阅全部告警或实时数据标识
@param [in] session				连接句柄
@param [in] subscribeflag		告警全部订阅标识 0 默认否 1 是
@param [in] distributeflag		分发设备授权标识 0 否 1 默认是
@return
@remarks 1、默认时，无须调用此接口 2、有需要，连接成功后立即调用
@see 
*/
DLIB_API t_int32 DMU_SC_SetSubAllAlarm(t_uint32 session, t_int32 subscribeflag = 0, t_int32 distributeflag = 1);

/**
@brief 操作告警或实时数据订阅
@param [in] session		连接句柄
@param [in] timeout		超时时间
@param [in] info		操作xml
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<opt
		type=""			子类型 0 告警订阅 1 实时数据订阅 2pgs信息 
		level=""		所有告警等级 -1 表示订阅告警 1~5表订阅等级统一修改位该等级
	>
		<item 
			operate=""	操作类型
			flag=""		0：订阅具体的设备；1：订阅组织；2:订阅通道
			devcode=""	设备代码(为组织时，填写路径)
			domid=""	设备域ID
			type=""		告警类型 -1 所有类型
			level=""	告警等级 5 高于等于该等级的告警都可以收到
		/>
		....

	</opt>
</root>
@endverbatim
@return
@remarks 订阅组织就是订阅组织及其下所有设备
@see 
*/
DLIB_API t_int32 DMU_SC_OptSubscribe(t_uint32 session, t_int32 timeout, char *info);


/**
@brief 操作告警或实时数据订阅（订阅用户）
@param [in] session		连接句柄
@param [in] timeout		超时时间
@param [in] info		操作xml
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<opt
		type=""			子类型 0 告警订阅 1 实时数据订阅 2pgs信息 3 订阅用户告警
		level=""		所有告警等级 -1 表示订阅告警 1~5表订阅等级统一修改为该等级
		userid=""       订阅用户的useid
	>
		<item 
			operate=""	操作类型
			flag=""		0：订阅具体的设备；1：订阅组织; 2 订阅通道; 
			flaguser=""	0 订阅用户 1 订阅用户组织
			devcode=""  设备编码（订阅组织时填组织路径 0-1-）
			userid=""	被订阅用户id(为组织时不填，下面orgpath填写路径)
			orgpath=""  被订阅用户组织路径
			domid=""	域ID
			type=""		告警类型 -1 所有类型
			level=""	告警等级 5 高于等于该等级的告警都可以收到
		/>
		......
	</opt>
</root>
@endverbatim
@return
@remarks 订阅组织就是订阅组织及其下所有用户
@see 
*/
DLIB_API t_int32 DMU_SC_OptSubscribeUser(t_uint32 session, t_int32 timeout, char *info);

/**
@brief 查询用户告警或实时数据订阅
@param [in] session		连接句柄
@param [in] timeout		超时时间
@param [in] subtype		子类型 0 告警订阅 1 实时数据订阅 2 设备GPS告警 3 用户告警
@param [in] userid		订阅用户userid；userId=0 查所有用户，userId!=0查指定用户。
@param [out] outxml		返回信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<item 
		userid=""		用户ID
		devcode=""		设备代码
		domid=""		设备域ID
		type=""			告警类型
		level=""		告警等级
	/>
</root>
@endverbatim
@param [in]  maxlen		信息最大长度
@return
@remarks
@see 
*/
DLIB_API t_int32 DMU_SC_QuerySubscribe(t_uint32 session, t_int32 timeout, t_int32 subtype, t_int32 userid, char *outxml, t_uint32 maxlen);


/**
@brief 查询用户告警或实时数据订阅
@param [in] session		连接句柄
@param [in] timeout		超时时间
@param [in] subtype		子类型 0 告警订阅 1 实时数据订阅
@param [out] outxml		返回信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<item 
		userid=""		用户ID(阿里订阅查询)，userId=0 查所有用户，userId!=0查指定用户。
		devcode=""		设备代码
		domid=""		设备域ID
		type=""			告警类型
		level=""		告警等级
	/>
</root>
@endverbatim
@param [in]  maxlen		信息最大长度
@return
@remarks
@see 
*/
//DLIB_API t_int32 DMU_SC_QueryUserSubscribe(t_uint32 session, t_int32 timeout, t_int32 subtype, char *outxml, t_uint32 maxlen);

/** @} */

/**
* @defgroup DMU_SDK查询告警数据
* @{
*/

/**
@brief 查询历史告警信息
@param [in]  session			连接句柄
@param [in]  timeout			超时时间
@param [in]	 info				条件信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<srcdomid />		发起域ID
	<starttime />		开始时间
	<endtime />			结束时间
	<type />			告警类型 -1 查询全部 其它查询指定
	<domid />			设备域ID
	<devcode />			通道设备代码，比如"'chn0','chn1','chn2'"
	<chnidx />			通道序号
	<domdevcode />		设备域ID+设备代码，比如"'chn0','chn1','chn2'@domid1; 'chn0','chn1','chn2'@domid2"
	<size />			每页大小
	<curpage />			查询第几页
	<orgcode />		    组织编码(orgcode跟devcode只能存在一个)
</root>
@endverbatim
@param [out] outxml				返回信息

// 注意devcode，如果是设备告警，devcode就是设备编码
// 如果是通道告警，devcode就是通道编码

@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total></total>				总数
	<item 
		id=""					告警记录ID
		domid=""				域ID
		devcode=""				设备代码
		devname=""				设备名称
		chnidx=""				通道索引
		devtype=""				设备类型
		type=""					告警类型
		status=""				状态
		level=""				告警等级
		alarmtime=""			告警时间
		length=""				数据长度
		msgtxt=""				消息文本
		confirmor=""			确认人
		confirmtime=""			确认时间
		confirmmsg=""			确认消息
		confirmstatus=""		确认状态
	/>
	...
</root>
@endverbatim
@param [in]  maxlen				信息最大长度
@return
@remarks
@see
*/
DLIB_API t_int32 DMU_SC_QueryHistoryAlarmInfo(t_uint32 session, t_int32 timeout, char *info, char *outxml, t_uint32 maxlen);

/**
@brief 操作告警确认信息
@param [in]  session			连接句柄
@param [in]  timeout			超时时间
@param [in]	 info				操作信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<confirmtime></confirmtime>	告警消息日期(处理告警时间)
	<item 
		id=""					告警记录ID
		confirmmsg=""			确认信息
		confirmstatus=""		确认状态 0 未确认 1 已确认
	/>
</root>
@endverbatim
@return
@remarks
@see
*/
DLIB_API t_int32 DMU_SC_OptAlarmConfirm(t_uint32 session, t_int32 timeout, char *info);


/**
@brief 操作批量用户告警确认信息
@param [in]  session			连接句柄
@param [in]  timeout			超时时间
@param [in]	 info				操作信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total><total>                 		总数
	<confirmmsg><confirmmsg>			确认消警意见
	<item
		revalarmusername=""				消警用户名称
		revalarmuserid=""				消警用户id
		username=""						告警用户名称（服务查DB）
		userid=""						告警用户id
		domid=""                        告警域ID
		devcode=""                      告警设备编码
		chncode=""						告警通道编码
		orgpath=""                      组织路径（服务查DB）
		devtype=""                      设备类型
		type=""							告警类型
		guid=""							告警guid 
		ackstatus=""                    告警状态确认：1、告警已处理  5、任务召回   6、任务已处理  7、消单 （枚举值跟上面查询的对应）----（二期新增）
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
@brief 查询案件告警信息
@param [in]  session                       连接句柄
@param [in]  timeout                      超时时间
@param [in]    info                                     条件信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
         <srcdomid />             发起域ID
         <starttime />            开始时间：2016-05-10 00:00:00
         <endtime />              结束时间
         <type />                 告警类型 -1 查询全部 其它查询指定4,201
         <domid />                设备域ID
         <status />               状态（查询告警状态,0是未处理，1是处理）
         <size />                 每页大小
         <curpage />              查询第几页,1表示第一页
		 <confirmstatus />        告警用户确认状态
		 <flaguser  />            1:subuserid就是告警用户的userid,查alarm_log表，查已经发送的告警状态，0：查询用户subuserid的告警，下面的subuserid填对应用户userid
		 <subuserid />            订阅用户ID,根据订阅用户的ID来查，subuserid<=0 就按照原先的普通查询，subuserid>0根据订阅查询
		 <devtype />              设备类型 -1 查询全部 其它查询指定几种，格式如：27,111,102,301
		 <flag />                 0:用下面的时间条件查询，1查询服务器过去24小时的数据
		 <flagtime />             0:按照等级时间排序查询，1、按照等级排序查询,2按照时间排序查询，3按照时间等级排序    备注：默认时间升序，等级升序排列
</root>
@endverbatim
@param [out] outxml                                  返回信息

// 注意devcode，如果是设备告警，devcode就是设备编码
// 如果是通道告警，devcode就是通道编码

@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
         <total></total>                                    总数
         <item 
                    id=""                                   告警记录ID
                   domid=""                                域ID
                   devcode=""                              设备代码
                   devname=""                              设备名称
                   chnidx=""                               通道索引
                   devtype=""                              设备类型
                   type=""                                 告警类型
                   status=""                               状态
                   level=""                                告警等级
                   alarmtime=""                            告警时间
                   length=""                               数据长度
                   msgtxt=""                               消息文本
                   confirmor=""                            确认人
                   confirmtime=""                          确认时间
                   confirmmsg=""                           确认消息
                   comfirmstatus=""                        确认状态
				   guid=""                                 告警guid
				   alarmstatus=""                          告警状态确认   
         />
</root>
@endverbatim
@param [in]  maxlen                                 信息最大长度
@return
@remarks
@see
*/
DLIB_API t_int32 DMU_SC_QueryAlarmCaseInfo(t_uint32 session, t_int32 timeout, char *info, char *outxml, t_uint32 maxlen);


/**
@brief 查询历史实时数据信息
@param [in]  session			连接句柄
@param [in]  timeout			超时时间
@param [in]  inxml				条件信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<srcdomid />		发起域ID
	<starttime />		开始时间
	<endtime />			结束时间
	<domid />			设备域ID
	<devcode />			通道设备代码，比如"'chn0';'chn1';'chn2'"
	<size />			每页大小
	<curpage />			查询第几页
</root>
@endverbatim
@param [out] outxml				返回信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total></total>				总数
	<item 
		domid=""				域ID
		devcode=""				设备代码
		devname=""				设备名称
		devtype=""				设备类型
		time=""					上报时间
		val=""					实时数据值
		unit=""					实时数据单位
	/>
</root>
@endverbatim
@param [in]  maxlen				信息最大长度
@return
@remarks
@see
*/
DLIB_API t_int32 DMU_SC_QueryHistoryRealData(t_uint32 session, t_int32 timeout, char* inxml, char* outxml, t_uint32 maxlen);


/**
@brief 查询历史实时数据的平均值
@param [in]  session			连接句柄
@param [in]  timeout			超时时间
@param [in]  inxml				条件信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<starttime />		开始时间
	<endtime />			结束时间
	<domid />			设备域ID
	<devcode />			设备编码
	<interval />		间隔的时间，单位秒
</root>
@endverbatim
@param [out] outxml				返回信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<item 
		domid=""				域ID
		devcode=""				设备代码
		devname=""				设备名称
		devtype=""				设备类型
		starttime=""			时间段开始时间
		endtime=""			    时间段结束时间
		val=""					时间段的平均值
		unit=""					实时数据单位
	/>
</root>
@endverbatim
@param [in]  maxlen				信息最大长度
@return
@remarks
@see
*/
DLIB_API t_int32 DMU_SC_QueryHistoryRealData_AVG(t_uint32 session, t_int32 timeout, char* inxml, char* outxml, t_uint32 maxlen);

/** @} */

/**
* @defgroup DMU_SDK告警等级
* @{
*/

/**
@brief 操作告警优先级
@param [in] session				连接句柄
@param [in] timeout				超时时间
@param [in] info				操作信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<opt 
		operate=""				操作类型
	>
		<item 
			devcode=""			设备代码
			domid=""			域ID
			type=""				告警类型
			level=""			告警等级
			updatetime=""		更新时间
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
* @defgroup DMU_SDK客户端告警
* @{
*/
/**
@brief 客户端向dmu发送客户端告警
@param [in] session				连接句柄
@param [in] timeout				超时时间
@param [in] inxml				查询的解码器
@verbatim
见DMU_SC_SetDmuMsg中的告警数据通知
@endverbatim
@return
@remarks
@see
*/
DLIB_API t_int32 DMU_SC_SendClientAlarm(t_uint32 session, t_int32 timeout,char* inxml);

/**
@brief 手机告警上报（阿里项目）
@param [in] session				连接句柄
@param [in] timeout				超时时间
@param [in] inxml				查询的解码器
@param [out] outguid			告警ID
@param [in]  maxlen				信息最大长度
@verbatim
见DMU_SC_SetDmuMsg中的告警数据通知
@endverbatim
@return
@remarks
@see
*/
DLIB_API t_int32 DMU_SC_SendPhoneClientAlarm(t_uint32 session, t_int32 timeout,char* inxml,char* outguid,t_uint32 maxlen);

/** @} */

/**
* @defgroup DMU_SDK实时数据
* @{
*/
/**
@brief 客户端向dmu发送客户端实时数据
@param [in] session				连接句柄
@param [in] timeout				超时时间
@param [in] inxml				gps信息
@verbatim
见DMU_SC_SetDmuMsg中的实时数据通知
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



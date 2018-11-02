/**
 * Copyright (c) 2014~2015, 浙江大华系统工程有限公司 All rights reserved.
 * \file		cmu_sdk.h
 * \brief		cmu_sdk
 * \author		24997
 * \date		2014年12月19日
 * \note		CMU SDK 接口
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
@brief 设置各个模块的设备网、局域网、外网
@param [in] cmu_session				CMU连接句柄
@param [in] unit_session			其他模块单元连接句柄
@param [in]  intranet_domain		设备网域  格式 ip|port  如1.1.1.1|9800 12U 2.5U设备内部单板交互的网络
@param [in]  lan_domain			    局域网域  格式 ip|port  如1.1.1.1|9800 12U 2.5U 1U 设备之间交互的网络
@param [in]  public_domain		    外网域  格式 ip|port  如1.1.1.1|9800	在公网和设备交互的网络

@return 
@remarks    42893 add 20180824
@see UnitCommon_Set_AllIP
*/
DLIB_API void UnitCommon_Set_AllIP(t_uint32 cmu_session,t_uint32 unit_session, char* intranet_domain, char* lan_domain,char *public_domain);



/**
* @defgroup CMU_SDK函数
* @{
*/

/**
* @defgroup CMU_SDK系统
* @{
*/
/**
@brief CMU_SDK初始化
@return 
@remarks 如果和其它SDK一起使用，需要最先调用此接口
@see CMU_SC_SetHeatbeat
*/
DLIB_API void CMU_SC_SetHeatbeat(t_int32 intervalTime, t_int32 outTime);

/**
@brief CMU_SDK初始化
@return 
@remarks 如果和其它SDK一起使用，需要最先调用此接口
@see CMU_SC_Cleanup
*/
DLIB_API t_int32 CMU_SC_Init();

/**
@brief CMU_SDK初始化
@return 
@remarks 如果和其它SDK一起使用，需要最先调用此接口
@see CMU_SC_Cleanup
*/
DLIB_API t_int32 CMU_SC_InitNoApp();

/**
@brief CMU_SDK初始化，单连接
@return 
@remarks 如果和其它SDK一起使用，需要最先调用此接口
@see CMU_SC_Cleanup
*/
DLIB_API t_int32 CMU_SC_InitSingle();

/**
@brief CMU_SDK反初始化
@return 
@remarks 如果和其它SDK一起使用，需要最后调用此接口
@see CMU_SC_Init
*/
DLIB_API t_int32 CMU_SC_Cleanup();

/**
@brief 设置日志文件的目录
@param [in] dir		日志文件的目录
@verbatim
注意：CMU_SC_SetLogDir设置日志文件的目录，给手机调用（在CMU_SC_Init之前调用），日志文件输出到指定目录。
注意和CMU_SC_SetLogCfgPath接口的区别，CMU_SC_SetLogCfgPath是读取一个日志配置文件，
这个文件里配置日志的输出级别，按照这个级别输出日志。
@endverbatim
@return 
@remarks
@see
*/
DLIB_API t_int32 CMU_SC_SetLogDir(char* dir);

/**
@brief 设置日志配置文件路径
@param [in] path 配置文件路径
@return 
@remarks
@see
*/
DLIB_API t_int32 CMU_SC_SetLogCfgPath(char* path);

/**
@brief 客户端记录日志
@param [in] level		日志等级
@verbatim
	0	调试日志
	1	信息日志
	2	接口日志
	3	警告日志
	4	错误日志
	5	致命日志
@endverbatim
@param [in] info		日志信息
@return 
@remarks
@see
*/
DLIB_API t_int32 CMU_SC_Log(t_uint32 level, char* info);

/**
@brief 客户端记录trace
@param [in] info		trace信息
@return 
@remarks
@see
*/
DLIB_API t_int32 CMU_SC_Trace(char* info);

/**
@brief 日志级别开关
@param [in] level		日志等级
@verbatim
	0	调试日志
	1	信息日志
	2	接口日志
	3	警告日志
	4	错误日志
	5	致命日志
@endverbatim
@param [in] flag		开关
@verbatim
0	关闭
1	开启
@endverbatim
@return 
@remarks
@see
*/
DLIB_API t_int32 CMU_SC_LogEnabled(t_uint32 level, t_int32 flag);

/** @} */

/**
* @defgroup CMU_SDK回调函数
* @{
*/

/**
@brief CMU SDK 消息回调函数定义
@param [in] handle		用户登录句柄
@param [in] data		消息数据
@param [in] dwBufSize		数据长度
@param [in] pUser		用户数据
@return 
@remarks
@see CMU_SC_SetMsg
*/
typedef t_int32 (*fIbpCmuMsgCallBack)(t_uint32 handle, char *data, t_uint32 bufSize, void* pUser);

/**
@brief 设置CMU SDK 回调函数
@param [in] cb		设置的回调函数
@param [in] pUser	用户数据
@return 
@remarks 回调消息示例
@verbatim
报告master信息
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="CMU" type="Request" cmd="reportMasterInfo" sequence="" session="0">
	<modulename></modulename>		模块名 比如 DMU, VTDU
	<domid></domid>				域ID
	<ipinfo></ipinfo>			IP信息10.36.65.89|9858;
	<svrid></svrid>				服务ID
	<accnum></accnum>			接入能力
	<adapnum></adapnum>			转发能力
</root>
@endverbatim
@verbatim
用户被踢掉
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root version="1.0" unit="CMU" type="Request" cmd="logout" sequence="" session="0">
	<domid></domid>				域ID
	<userid></userid>			用户ID
	<username></username>			用户名称
	<strdata></strdata>			字符串数据
	<intdata></intdata>			数字数据
</root>
@endverbatim
@verbatim
服务online消息通知
<?xml version='1.0' encoding='utf-8' ?>
<root version="1.0" unit="CMU" type="onlineNotify" cmd="onlineNotify" sequence="0" length="0">
	<server 
		servername="" 			服务名称
		session="" 			服务句柄
		status="" 			上下线状态
	/>
</root>
@endverbatim
@verbatim
设备信息通知消息
<?xml version='1.0' encoding='utf-8' ?>
<root version="1.0" unit="CMU" type="Notify" cmd="sharedDeviceNotify" sequence="">
	<user userid="1" username="admin"/>
	<device domid="" devcode=""  title=""/>
</root>
@endverbatim
@verbatim
用户登陆消息
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
* @defgroup CMU_SDK登陆登出
* @{
*/

/**
@brief 用户登录
@param [in]  timeout		超时时间
@param [in]  domainId		域ID
@param [in]  ip			服务IP
@param [in]  port		服务端口
@param [in]  username		用户名
@param [in]  userpass		用户密码
@param [out] outxml		返回信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<handle></handle>		登陆成功返回的句柄
	<userid></userid>		返回的用户ID
	<domid></domid>			返回的用户域ID
	<handle></handle>		返回的用户handle
</root>
@endverbatim
@param [in]  maxlen		信息最大长度
@return 200 成功 其它 失败
@remarks
@see CMU_SC_Logout
*/
DLIB_API t_int32 CMU_SC_Login(t_int32 timeout, char* domainId, char* ip, t_uint32 port, char *username, char *userpass, char* outxml, t_uint32 maxlen);

/**
@brief 用户登录接口（增加了登录用户类型）
@param [in]  timeout		超时时间
@param [in]  info		操作信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<ip>CMU的IP地址</ip>
	<port>CMU的端口，一般是9800</port>
	<username>登录用户名</username>
	<userpass>登录用户名</userpass>
	<type>登录类型，:调度台1:Web客户端操作员登录2:手机客户端登录3:PC客户端登录5:从其它平台51:Web客户端管理员登录</type>
	<imei>手机客户端登录需填写imei以启用手机绑定功能，不填写则不启用该功能</imei>
	<ipinfo></ipinfo>本地的ip地址
</root>
@endverbatim
@param [out] outxml		返回信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<handle>3</handle>							登陆成功返回的句柄
	<userid>1</userid>							返回的用户ID
	<domid>27477</domid>						返回的用户域ID
	<groupid>123123</groupid>					用户绑定的组号
	<groupmember>615001</groupmember>			用户绑定的真实号码
	<groupmemberpwd>dahua1187!</groupmemberpwd> 用户绑定号码的密码
	<session>19718</session>					返回的用户session
	<errmsg/>									错误信息
</root>
@endverbatim
@param [in]  maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_Logout
*/
DLIB_API t_int32 CMU_SC_LoginEx(t_int32 timeout, char* info, char* outxml, t_uint32 maxlen);

/**
@brief 用户是否已经登录
@param [in] handle		登陆句柄
@return 0 未登录 1 已登录
@remarks
@see CMU_SC_Login
*/
DLIB_API t_int32 CMU_SC_IsLogin(t_uint32 handle);

/**
@brief 用户登出
@param [in] handle		登陆句柄
@return 
@remarks
@see CMU_SC_Login
*/
DLIB_API t_int32 CMU_SC_Logout(t_uint32 handle);

/** @} */

/**
* @defgroup CMU_SDK组织管理
* @{
*/

/**
@brief 查询指定组织详细信息
@param [in]  handle		登陆句柄
@param [in]  timeout		超时时间
@param [in]  domid		组织域ID
@param [in]  orgcode		组织代码
@param [out] outxml		查询信息(详见CMU_SC_OptOrg注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" />
</root>
@endverbatim
@param [in]  maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptOrg
*/
DLIB_API t_int32 CMU_SC_QueryOrg(t_uint32 handle, t_int32 timeout, char* domid, char* orgcode, char*outxml, t_uint32 maxlen);

/**
@brief 查询所有组织
@param [in]  handle		登陆句柄
@param [in]  timeout		超时时间
@param [out] outxml		查询信息(详见CMU_SC_OptOrg注释)
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
@param [in]  maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptOrg
*/
DLIB_API t_int32 CMU_SC_QueryAllOrg(t_uint32 handle, t_int32 timeout, char*outxml, t_uint32 maxlen);

/**
@brief 查询所有组织(增加权限功能)
@param [in]  handle		登陆句柄
@param [in]  timeout		超时时间
@param [in]	 info				输入信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<funid></funid>
</root>
@endverbatim
@param [out] outxml		查询信息(详见CMU_SC_OptOrg注释)
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
@param [in]  maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptOrg
*/
DLIB_API t_int32 CMU_SC_QueryAllOrgEx(t_uint32 handle, t_int32 timeout, char *info, char*outxml, t_uint32 maxlen);

/**
@brief 按照条件查询所有组织
@param [in]  handle		登陆句柄
@param [in]  timeout		超时时间
@param [in] info		操作信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<orgdomid></orgdomid>空:全部
	<orgcode></orgcode>空:全部
	<orgtype></orgtype>-1:全部 1:组织 2:区域 3:部门，多种类型用逗号(",")分隔
</root>
@endverbatim
@param [out] outxml		查询信息(详见CMU_SC_OptOrg注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" orgtype=""/>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" orgtype=""/>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" orgtype=""/>
</root>
@endverbatim
@param [in]  maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptOrg
*/
DLIB_API t_int32 CMU_SC_QueryOrgEx(t_uint32 handle, t_int32 timeout, char *info, char*outxml, t_uint32 maxlen);

/**
@brief 查询子组织
@param [in]  handle		登陆句柄
@param [in]  timeout		超时时间
@param [in]  domid		域ID
@param [in]  parentorgcode	父组织代码(为空字符串返回根组织信息)
@param [out] outxml		查询信息(详见CMU_SC_OptOrg注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" />
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" />
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" />
</root>
@endverbatim
@param [in]  maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptOrg
*/
DLIB_API t_int32 CMU_SC_QuerySubOrg(t_uint32 handle, t_int32 timeout, char* domid, char* parentorgcode, char*outxml, t_uint32 maxlen);

/**
@brief 查询子组织
@param [in]  handle		登陆句柄
@param [in]  timeout		超时时间
@param [in]  domid		域ID
@param [in]  parentorgcode	父组织代码(为空字符串返回根组织信息)
@param [out] outxml		查询信息(详见CMU_SC_OptOrg注释)
@verbatim
见 CMU_SC_QuerySubOrg
@endverbatim
@param [in]  maxlen		信息最大长度
@return 
@remarks 区别于CMU_SC_QuerySubOrg，对于当前用户，如果一个组织下面可以操作的设备为0，过滤掉这个组织
@see CMU_SC_OptOrg
*/
DLIB_API t_int32 CMU_SC_QuerySubOrg_FilterEmpty(t_uint32 handle, t_int32 timeout, char* domid, char* parentorgcode, char*outxml, t_uint32 maxlen);

/**
@brief 查询子组织（需要释放返回对象内存）
@param [in]  handle		登陆句柄
@param [in]  timeout		超时时间
@param [in]  domid		域ID
@param [in]  parentorgcode	父组织代码(为空字符串返回根组织信息)
@param [out] errorcode		错误码
@param [out]  reallen		信息实际长度
@return 
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" />
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" />
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" />
</root>
@endverbatim
@remarks 请释放返回对象内存！请释放返回对象内存！请释放返回对象内存！
@see CMU_SC_OptOrg
*/
DLIB_API char* CMU_SC_QuerySubOrgXXXX(t_uint32 handle, t_int32 timeout, char* domid, char* parentorgcode, t_int32 *errorcode, t_uint32 *reallen);

/**
@brief 查询自定义分组
@param [in]	session			登陆句柄
@param [in]	timeout			超时时间
@param [in]	 info				输入信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<!--userid，parentid，id三个字段同时只能填一个，其他两个字段填-1-->
	<userid>分组所属用户id</userid>
	<parentid>分组父节点id</parentid>
	<id>分组id</id>
	<issuborg>0</issuborg> 是否要查询子节点  1查询, 0不查询, 没有字段时查询  只在按userid查询时生效
	<type></type> //增加查询类型,默认不填查询2调度台分组 ,填入值则查询指定分组,3 查询视频设备分组
	<size>每页返回记录的数量</size>
	<curpage>第几页，从0开始</curpage>
</root>
@endverbatim
@param [out] outxml				返回信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total></total>
	<group id="分组id"
		parentid="分组父节点ID"
		name="分组名称，64字节，添加、修改有效"
		type="分组类型，通讯录分组:1"
	>
		<group id="" parentid="" name="" type="">
			<group id="" parentid="" name="" type=""/>
		</group>
	</group>
</root>
@endverbatim
@param [in]  maxlen				信息最大长度
@return 
@remarks 未分组的查不到
@see 
*/
DLIB_API t_int32 CMU_SC_QueryGroup(t_uint32 session, t_int32 timeout, char *info, char *outxml, t_uint32 maxlen);

/**
@brief 查询自定义分组下面的对象
@param [in]	session			登陆句柄
@param [in]	timeout			超时时间
@param [in]	 info				输入信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<groupid></groupid>
	<funcid></funcid>需要过滤设备的权限类型
	<size>每页返回记录的数量</size>
	<curpage>第几页，从0开始</curpage>
</root>
@endverbatim
@param [out] outxml				返回信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total></total>
	<group id="分组id"
		parentid="分组父节点ID"
		name="分组名称，64字节，添加、修改有效"
		type="分组类型，通讯录分组:1"
	>
		<device devid="3844" domid="73807" devcode="88888channel1" devtype="31" manufid="1" title="閫氶亾1" status="2" orgdomid="73807" orgcode="1" devpath="0-3772-" orgpath="0-1-522" devlinktype="0" updatetime="2016-09-01 20:16:56"/>
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
@param [in]  maxlen				信息最大长度
@return 
@remarks 未分组的查不到
@see 
*/
DLIB_API t_int32 CMU_SC_QueryGroupObject(t_uint32 session, t_int32 timeout, char *info, char *outxml, t_uint32 maxlen);

/**
@brief 查询子组织
@param [in]  handle		登陆句柄
@param [in]  timeout		超时时间
@param [in] info		操作信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<funid></funid>
	<domid></domid>
	<parentorgdomid></parentorgdomid>
	<parentorgcode></parentorgcode>
	<orgtype></orgtype>-1:全部 1:组织 2:区域 3:部门，多种类型用逗号(",")分隔
</root>
@endverbatim
@param [out] outxml		查询信息(详见CMU_SC_OptOrg注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" orgtype=""/>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" orgtype=""/>
	<org domid="" orgcode="" parentdomid="" parentorgcode="" orgpath="" orgposidx="" title="" updatetime="" desc="" orgtype=""/>
</root>
@endverbatim
@param [in]  maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptOrg
*/
DLIB_API t_int32 CMU_SC_QuerySubOrgEx(t_uint32 handle, t_int32 timeout, char *info, char*outxml, t_uint32 maxlen);

/** @} */

/**
* @defgroup CMU_SDK设备管理
* @{
*/

/**
@brief 通过组织查询设备主要信息
@param [in]  handle		登陆句柄
@param [in]  timeout		超时时间
@param [in]  domid		组织域ID
@param [in]  orgcode		组织代码
@param [out] outxml		查询信息(详见CMU_SC_OptDevice注释)
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
			//可选绑定信息
			<item domid="" devcode="" slavedomid="" slavedevcode="" />
			<item domid="" devcode="" slavedomid="" slavedevcode="" />
		</device>
	</org>
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDevice(t_uint32 handle, t_int32 timeout, char* domid, char* orgcode, char*outxml, t_uint32 maxlen);

/**
@brief 通过组织查询设备信息(根据设备类型)
@param [in]  handle		登陆句柄
@param [in]  timeout		超时时间
@param [in]  domid			组织域ID
@param [in]  orgcode		组织代码
@param [in]  devtype		设备类型(""全部, 多个条件用逗号分隔，如"1,2,3")
@param [out] outxml			查询信息(详见CMU_SC_OptDevice注释)
@verbatim
//具体根据设备类型决定返回信息，主要信息如下：
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode=""  orgpath="" title="" updatetime="" desc="" >
		<device domid="" devcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" devlinktype="" display="" updatetime="" />
	</org>
</root>
//一次设备
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode=""  orgpath="" title="" updatetime="" desc="" >
		<device domid="" devcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" devlinktype="" detecttype="" detectpart="" targettype="" typedesc="" ratedcurrent="" heatfeature="" faultdesc="" sequence="" time="" installspot="" installtime="" maintainer="" model="" visible="" desc="" />
		<device domid="" devcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" devlinktype="" detecttype="" detectpart="" targettype="" typedesc="" ratedcurrent="" heatfeature="" faultdesc="" sequence="" time="" installspot="" installtime="" maintainer="" model="" visible="" desc="" />
	</org>
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDeviceEx(t_uint32 handle, t_int32 timeout, char* domid, char* orgcode, char *devtype, char*outxml, t_uint32 maxlen);

/**
@brief 通过组织和功能权限查询设备主要信息
@param [in]  handle		登陆句柄
@param [in]  timeout		超时时间
@param [in]  domid		组织域ID
@param [in]  orgcode		组织代码
@param [in]  funcid			功能权限ID
@param [out] outxml		查询信息(详见CMU_SC_OptDevice注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode=""  orgpath="" title="" updatetime="" desc="" >
		<device domid="" devcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" />
	</org>
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDeviceByFuncId(t_uint32 handle, t_int32 timeout, char* domid, char* orgcode, t_int32 funcid, char*outxml, t_uint32 maxlen);

/**
@brief 通过组织和功能权限查询设备主要信息(根据设备类型)
@param [in]  handle		登陆句柄
@param [in]  timeout		超时时间
@param [in]  domid		组织域ID
@param [in]  orgcode		组织代码
@param [in]  devtype		设备类型(""全部, 多个条件用逗号分隔，如"1,2,3")
@param [in]  funcid			功能权限ID
@param [out] outxml		查询信息(详见CMU_SC_OptDevice注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<org domid="" orgcode="" parentdomid="" parentorgcode=""  orgpath="" title="" updatetime="" desc="" >
		<device domid="" devcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" />
	</org>
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDeviceByFuncIdEx(t_uint32 handle, t_int32 timeout, char* domid, char* orgcode, char* devtype, t_int32 funcid, char*outxml, t_uint32 maxlen);

/**
@brief 根据设备查询设备详细信息
@param [in]  handle		登陆句柄
@param [in]	 timeout	超时时间
@param [in]	 domid		设备域ID
@param [in]	 devcode	设备代码
@param [in]	 devtype	设备类型(未知类型填0)
@param [out] outxml		查询信息(详见CMU_SC_OptDevice注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<device domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" display="" devlinktype="" updatetime="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" >
		<channel domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" chnidx="" accesory="" lighttype="" guardtype="">
			//可选绑定信息
			<item domid="" devcode="" slavedomid="" slavedevcode="" />
			<item domid="" devcode="" slavedomid="" slavedevcode="" />
		</channel>
		//可选绑定信息
		<item domid="" devcode="" slavedomid="" slavedevcode="" />
		<item domid="" devcode="" slavedomid="" slavedevcode="" />
	</device>
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDevDetail(t_uint32 handle, t_int32 timeout, char* domid, char* devcode, t_int32 devtype, char*outxml, t_uint32 maxlen);

/**
@brief 根据设备和功能权限查询设备详细信息
@param [in]  handle		登陆句柄
@param [in]	 timeout	超时时间
@param [in]	 domid		设备域ID
@param [in]	 devcode	设备代码
@param [in]	 devtype	设备类型(未知类型填0)
@param [in]  funcid			功能权限ID
@param [out] outxml		查询信息(详见CMU_SC_OptDevice注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<device domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" >
		<channel domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" chnidx="" accesory="" />
	</device>
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDevDetailByFuncId(t_uint32 handle, t_int32 timeout, char* domid, char* devcode, t_int32 devtype, t_int32 funcid, char* outxml, t_uint32 maxlen);

/**
@brief 根据通道查询设备详细信息
@param [in]  handle		登陆句柄
@param [in]	 timeout	超时时间
@param [in]	 domid		通道域ID
@param [in]	 chncode	通道代码
@param [out] outxml		查询信息(详见CMU_SC_OptDevice注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<device domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" >
		<channel domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" chnidx="" accesory="" />
	</device>
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDevByChn(t_uint32 handle, t_int32 timeout, char* domid, char* chncode, char* outxml, t_uint32 maxlen);

/**
@brief 通过组织查询设备列表详细信息(分页)
@param [in]  handle		登陆句柄
@param [in]  timeout		超时时间
@param [in]  domid			组织域ID
@param [in]  code			组织代码
@param [in]	 size			页大小
@param [in]	 curpage		当前页(从0开始)
@param [out] outxml			查询信息(详见CMU_SC_OptDevice注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total></total>			总条数
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDevDetailByCode(t_uint32 handle, t_int32 timeout, char* domid, char* code, t_int32 size, t_int32 curpage, char* outxml, t_uint32 maxlen);

/**
@brief 通过组织和设备类型查询设备列表详细信息(分页)
@param [in]  handle		登陆句柄
@param [in]  timeout		超时时间
@param [in]  domid			组织域ID
@param [in]  code			组织代码
@param [in]  devtype		设备类型(""全部, 多个条件用逗号分隔，如"1,2,3")
@param [in]	 size			页大小
@param [in]	 curpage		当前页(从0开始)
@param [out] outxml			查询信息(详见CMU_SC_OptDevice注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total></total>			总条数
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDevDetailByCodeEx(t_uint32 handle, t_int32 timeout, char* domid, char* code, char *devtype, t_int32 size, t_int32 curpage, char* outxml, t_uint32 maxlen);

/**
@brief 根据条件查询设备主要（详细）信息
@param [in]  handle		登陆句柄
@param [in]  timeout		超时时间
@param [in]  domid			组织域ID（""全部）
@param [in]  code			组织代码（""全部）
@param [in]	 devname		设备名称（""全部）
@param [in]	 devtype		设备类型(0全部)
@param [in]	 manuftype		厂商类型(-1全部)
@param [in]	 status			在线状态(0全部 1 在线 2 不在线)
@param [in]	 size			页大小
@param [in]	 curpage		当前页(从0开始)
@param [out] outxml			查询信息(详见CMU_SC_OptDevice注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total></total>			总条数
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDevBrief(t_uint32 handle, t_int32 timeout, char* domid, char* code, char *devname, t_int32 devtype, t_int32 manuftype, t_int32 status, t_int32 size, t_int32 curpage, char* outxml, t_uint32 maxlen);

/**
@brief 根据条件查询设备主要（详细）信息
@param [in]  handle		登陆句柄
@param [in]  timeout		超时时间
@param [in]  info			条件信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<domid />				组织域ID（""全部）
	<code />				组织代码（""全部）
	<devname />				设备名称（""全部）
	<devtype />				设备类型(""全部, 多个条件用逗号分隔，如"1,2,3")
	<manuftype />			厂商类型(-1全部)
	<status />				在线状态(0全部 1 在线 2 不在线)
	<size />				页大小
	<curpage />				当前页(从0开始)
	<isSubOrg />			是否查询子节点1查 0不查
</root>
@endverbatim		
@param [out] outxml			查询信息(详见CMU_SC_OptDevice注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total></total>			总条数
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryDevBriefEx(t_uint32 handle, t_int32 timeout, char *info, char* outxml, t_uint32 maxlen);

/**
@brief 根据号码查询话机主要（详细）信息
@param [in]  handle		登陆句柄
@param [in]  timeout		超时时间
@param [in]  info			条件信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<domid />				组织域ID（""全部）
	<code />				组织代码（""全部）
	<number />				话机号码（""全部）
	<devname />				话机名称（""全部）
	<devtype />				设备类型(""全部, 多个条件用逗号分隔，如"1,2,3")
	<size />				页大小
	<curpage />				当前页(从0开始)
	<isSubOrg />			是否查询子节点1查 0不查
</root>
@endverbatim		
@param [out] outxml			查询信息(详见CMU_SC_OptDevice注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<total></total>			总条数
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
	<item domid="" devcode="" parentdomid="" parentdevcode="" orgdomid="" orgcode="" devpath="" orgpath="" devtype="" manufid="" title="" status="" devposidx="" updatetime="" extend="" loginname="" loginpwd="" ipaddr="" portdev="" streamtype="" contrator="" locationid="" installspot="" installtime="" maintainer="" phone="" model="" visible="" longitude="" latitude="" desc="" orgname="" />
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptDevice
*/
DLIB_API t_int32 CMU_SC_QueryPhoneDevBriefEx(t_uint32 handle, t_int32 timeout, char *info, char* outxml, t_uint32 maxlen);
/** @} */

/**
* @defgroup CMU_SDK用户角色管理
* @{
*/

/**
@brief 查询本级域用户信息
@param [in]  handle		登陆句柄
@param [in]	 timeout	超时时间
@param [in]	 userid		用户ID
@param [out] outxml		查询信息(详见CMU_SC_OptUser注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<user userid="" usertype="" treeid="" username="" creatorid="" loginname="" loginpwd="" telephone="" status="" ip="" updatetime="" begindate="" enddate="" lockstatus="" orgdomid="" orgcode=""  medianum="" email="" multi="" flag="" extradata="" imei=""/>
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptUser
*/
DLIB_API t_int32 CMU_SC_QueryUser(t_uint32 handle, t_int32 timeout, t_int32 userid, char*outxml, t_uint32 maxlen);

/**
@brief 查询本级域用户信息扩展接口
@param [in]  handle		登陆句柄
@param [in]	 timeout	超时时间
@param [in]	 inxml		输入信息
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<infotype/>		//要查询的内容
	<user userid="" domainid="" orgdomid="" loginfrom=""/>
</root>
@param [out] outxml		输出信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<errcode/>
	<errmsg/>
	<user userid="" usertype="" treeid="" username="" creatorid="" loginname="" loginpwd="" telephone="" status="" ip="" updatetime="" begindate="" enddate="" lockstatus="" orgdomid="" orgcode=""  medianum="" email="" multi="" flag="" extradata="" imei=""/>
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
*/
DLIB_API t_int32 CMU_SC_QueryUserInfoEx(t_uint32 handle, t_int32 timeout, char* inxml, char* outxml, t_uint32 maxlen);

/**
@brief 按域查询用户信息
@param [in]  handle		登陆句柄
@param [in]	 timeout	超时时间
@param [in]	 domid		域编码
@param [in]	 userid		用户ID
@param [out] outxml		查询信息(详见CMU_SC_OptUser注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<user userid="" usertype="" treeid="" username="" creatorid="" loginname="" loginpwd="" telephone="" status="" ip="" updatetime="" begindate="" enddate="" lockstatus="" orgdomid="" orgcode=""  medianum="" email="" multi="" flag="" extradata=""	/>
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptUser
*/
DLIB_API t_int32 CMU_SC_QueryDomUser(t_uint32 handle, t_int32 timeout, char *domid, t_int32 userid, char*outxml, t_uint32 maxlen);

/**
@brief 查询组织下用户
@param [in]  handle		登陆句柄
@param [in]	 timeout	超时时间
@param [in]	 domid		组织域ID
@param [in]	 orgcode	组织代码
@param [out] outxml		查询信息(详见CMU_SC_OptUser注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<user userid="" usertype="" treeid="" username="" creatorid="" loginname="" loginpwd="" telephone="" status="" ip="" updatetime="" begindate="" enddate="" lockstatus="" orgdomid="" orgcode=""  medianum="" email="" multi="" flag="" extradata="" imei=""/>
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptUser
*/
DLIB_API t_int32 CMU_SC_QueryUserByOrg(t_uint32 handle, t_int32 timeout, char* domid, char* orgcode, char*outxml, t_uint32 maxlen);

/**
@brief 查询用户信息扩展接口
@param [in]  handle		登陆句柄
@param [in]	 timeout	超时时间
@param [in]	 info		输入信息
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<orgcode></orgcode>		查询的组织结构id(必填)
	<domid></domid>			查询的组织结构域id(必填)
	<username></username>	查询的用户名(选填)
	<funcid></funcid>		功能id(现在不过滤权限)
	<size></size>			分页数(必填)
	<curpage></curpage>		当前显示页(必填)
</root>
@endverbatim
@param [out] outxml		查询信息(详见CMU_SC_OptUser注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<user userid="" usertype="" treeid="" username="" creatorid="" loginname="" loginpwd="" telephone="" status="" ip="" updatetime="" begindate="" enddate="" lockstatus="" orgdomid="" orgcode=""  medianum="" email="" multi="" flag="" extradata="" imei=""/>
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_QueryUserEx
*/
DLIB_API t_int32 CMU_SC_QueryUserEx(t_uint32 handle, t_int32 timeout,char* inxml,char* outxml, t_uint32 maxlen);

/**
@brief 只查询当前组织下用户
@param [in]  handle		登陆句柄
@param [in]	 timeout	超时时间
@param [in]	 domid		组织域ID
@param [in]	 orgcode	组织代码
@param [in]	 funcid	
@param [out] outxml		查询信息(详见CMU_SC_OptUser注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<user userid="" usertype="" treeid="" username="" creatorid="" loginname="" loginpwd="" telephone="" status="" ip="" updatetime="" begindate="" enddate="" lockstatus="" orgdomid="" orgcode=""  medianum="" email="" multi="" flag="" extradata="" imei=""/>
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptUser
*/
DLIB_API t_int32 CMU_SC_QueryUserByThisOrg(t_uint32 handle, t_int32 timeout, char* domid, char* orgcode, int funcid, char*outxml, t_uint32 maxlen);

/**
@brief 查询所有用户
@param [in]  handle		登陆句柄
@param [in]	 timeout	超时时间
@param [out] outxml		查询信息(详见CMU_SC_OptUser注释)
@verbatim
<?xml version='1.0' encoding='utf-8' standalone='no' ?>
<root>
	<user domid="" userid="" usertype="" treeid="" username="" creatorid="" loginname="" loginpwd="" telephone="" status="" ip="" updatetime="" begindate="" enddate="" lockstatus="" orgdomid="" orgcode=""  medianum="" email="" multi="" flag="" extradata="" />
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks
@see CMU_SC_OptUser
*/
DLIB_API t_int32 CMU_SC_QueryAllUser(t_uint32 handle, t_int32 timeout, char*outxml, t_uint32 maxlen);

/**
@brief 查询当前在线用户
@param [in]  handle	登陆句柄
@param [in]	 timeout	超时时间
@param [out] outxml		查询信息
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
@param [in]	 maxlen		信息最大长度
@return 
@remarks
*/
DLIB_API t_int32 CMU_SC_QueryOnlineUser(t_uint32 handle, t_int32 timeout, char*outxml, t_uint32 maxlen);


/**
@brief 查当前在线用户的扩展接口
@param [in]  handle	登陆句柄
@param [in]	 timeout	超时时间
@param [in]	 imxml		操作信息
@verbatim
<root>
	<user userid="1" />
	<user userid="2" />
	<user userid="3" />
	<user userid="7" />
</root>
@endverbatim
@param [out] outxml		查询信息
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
@param [in]	 maxlen		信息最大长度
@return 
@remarks CMU_SC_QueryOnlineUser是查询所有的在线用户，
	CMU_SC_QueryOnlineUser_Ex是扩展接口，这个接口按照用户需求，查询指定的用户，相当于填空题，inxml为""表示查询所有。
*/
DLIB_API t_int32 CMU_SC_QueryOnlineUser_Ex(t_uint32 handle, t_int32 timeout, char* inxml, char* outxml, t_uint32 maxlen);



/**
@brief 查询当前在线用户的Id
@param [in]  handle	登陆句柄
@param [in]	 timeout	超时时间
@param [in]	 imxml		操作信息
@verbatim
<root>
	<isDetail></isDetail>	是否需要用户详细信息 1 查询详细信息
	<orgcode></orgcode>		查询的组织结构id
	<domid></domid>			查询的组织结构域id
	<number></number>		查询的用户号码
	<username></username>	查询的用户名
	<status></status>		查询的用户是否在线 -1 全部 0 不在线 1在线
	<funcid></funcid>		功能id
	<order></order>			排序方式 1 按用户名拼音排序(英文在前中文在后)
	<size></size>			分页数(必填)
	<curpage></curpage>		当前显示页(必填)
</root>
@endverbatim
@param [out] outxml		查询信息
@verbatim
<root>
	<user userid="1" />
	<user userid="2" />
	<user userid="3" />
	<user userid="7" />
</root>
@endverbatim
@param [in]	 maxlen		信息最大长度
@return 
@remarks CMU_SC_QueryOnlineUser返回在线用户以及绑定的信息，CMU_SC_QueryOnlineUser_Id仅仅返回在线用户的ID
*/
DLIB_API t_int32 CMU_SC_QueryOnlineUser_Id(t_uint32 handle, t_int32 timeout,char* inxml, char* outxml, t_uint32 maxlen);

/** @} */

#ifdef __cplusplus
}
#endif

#endif



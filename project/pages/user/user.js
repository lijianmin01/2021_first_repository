// pages/user/user.js


Page({

    /**
     * 页面的初始数据
     */
    data: {
        userImgPath:"/static/images/user/user.png",
        src:"",
        /*用户状态 */
        userStatus:"未登录",
        userName:"***",
        userWords:"***************************",
        userInformationRight1:"none",
        userInformationRight2:"block",
        theme:'light',
    },

    /**
     * 获取用户信息
     */
    getUserInfo:function () {
        var that=this;
        wx.getUserInfo({
          success(res){
            // console.log(res)
            that.setData({
                userImgPath:res.userInfo.avatarUrl,
                userName:res.userInfo.nickName,
                userWords:res.userInfo.country+"  ,  "+res.userInfo.province,
                userInformationRight1:"block",
                userInformationRight2:"none",
            })
          }
        })
    },
    /**
     * 生命周期函数--监听页面加载
     */
    onLoad: function (options) {
         // var base64 = require("/static/images/user/base64.js");
         this.setData({
            icon: '/static/images/user/icon_intro.png'
        });
    },
    /**
     * 打开摄像头
     */
    openCamera:function() {
        cam = wx.createCameraContext();
    },


    /**
     * 生命周期函数--监听页面初次渲染完成
     */
    onReady: function () {

    },

    /**
     * 生命周期函数--监听页面显示
     */
    onShow: function () {

    },

    /**
     * 生命周期函数--监听页面隐藏
     */
    onHide: function () {

    },

    /**
     * 生命周期函数--监听页面卸载
     */
    onUnload: function () {

    },

    /**
     * 页面相关事件处理函数--监听用户下拉动作
     */
    onPullDownRefresh: function () {

    },

    /**
     * 页面上拉触底事件的处理函数
     */
    onReachBottom: function () {

    },

    /**
     * 用户点击右上角分享
     */
    onShareAppMessage: function () {

    },
})
// pages/bind/bind.js
Page({

    /**
     * 页面的初始数据
     */
    data: {
        message:"Hello World !",
        name:NaN,
        path:"/static/touxiang.jpg",
        localPath:"未知"
    },

    /**
     * 生命周期函数--监听页面加载
     */
    onLoad: function (options) {

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

    /**
     * 点击修改数据
     */
    changeData: function(){
        // 获取数据
        console.log(this.data.message);

        // 修改数据（错误，只修改后端）
        //this.data.message = "Hello New World !";

        this.setData({ message:"Hello New World !"});
    },

    getUserName: function(){
        // wx.openSetting({});
        //获取用户名
        wx.getUserInfo({
            // 调用成功
            success:function(res){
                console.log(res);
            },
            // 失败
            fail:function(res){
                console.log(res);
            }
        })
    },
    // 方法二 获取用户信息
    xxxx: function(){
        var that = this;
        //获取用户名
        wx.getUserInfo({
            // 调用成功
            success:function(res){
                console.log(res);
                that.setData({
                    path:res.userInfo.avatarUrl,
                    name:res.userInfo.nickName
                })
            },
            // 失败
            fail:function(res){
                console.log("失败"+res);
            }
        })
    },
    getLocalPath: function () {
        var that=this;
        wx.chooseLocation({
          success: function(res){
              console.log(res);
              that.setData({
                  localPath:res.address,
              })
          },
          fail:function(){
              console.log("获取位置失败");
          }
        })
    }
})
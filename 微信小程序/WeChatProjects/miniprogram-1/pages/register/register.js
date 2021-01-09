// pages/register/register.js
Page({

    /**
     * 页面的初始数据
     */
    data: {
        phone:"***",
        code:NaN,
    },

    bindTxt: function (e) {
      console.log(e);  
      this.setData({
          phone:e.detail.value,
      })
    },
    bindCode:function(e) {
        this.setData({
            code:e.detail.value,
        })
    },

    /**
     * 登录
     */
    login:function(){
        wx.request({
          url: 'url',
          data: {phone:this.data.phone,code:this.data.code},
          method: "POST",
          success:function(res){

          },
        //   dataType: dataType,
        //   enableCache: true,
        //   enableHttp2: true,
        //   enableQuic: true,
        //   header: header,
        //   method: "POST",
        //   responseType: responseType,
        //   timeout: 0,
        //   success: (result) => {},
        //   fail: (res) => {},
        //   complete: (res) => {},
        })
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

    }
})
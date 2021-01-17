// pages/publish/publish.js
Page({

    /**
     * 页面的初始数据
     */
    data: {
        //初始值设置为显示
        none:"block"
    },
    aa(){
        var that= this
        //判断元素为显示还是隐藏并做相应操作
        if(that.data.none == "none"){
          that.setData({
            none:"block"
          })
        }else{
          that.setData({
            none:"none"
          })
        }
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
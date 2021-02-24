// pages/progress/progress.js
Page({

    /**
     * 页面的初始数据
     */
    data: {
        imageList: [
            {id: "1", title: "图片一", precent: 10},
            {id: "2", title: "图片二", precent: 20},
            {id: "3", title: "图片三", precent: 40},
        ]
    },
    /**
     * 改变进度
     */
    changePercent: function () {
        this.setData({
            ["imageList[0].precent"]: 80,
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
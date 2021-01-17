// pages/topic/topic.js
Page({

    /**
     * 页面的初始数据
     */
    data: {
        topicList:[
            {id:1,title:"春节买不到票",count:300},
            {id:2,title:"票太少",count:200},
            {id:3,title:"票价太贵",count:160},
        ],
    },
    /**
     * 返回上一级路径
     */
    backFather:function (e) {
        var topicInfo = e.currentTarget.dataset.xx;

        // 方一
        // // 获取所有页面
        // var pages = getCurrentPages();
        // // 获取之前界面对象
        // var prevPage = pages[pages.length-2];
        // prevPage.setData({
        //     topicInfo:topicInfo.title,
        // })

        // 方二
        // 获取所有页面
        var pages = getCurrentPages();
        // 获取之前界面对象
        var prevPage = pages[pages.length-2];
        prevPage.setTopicData(topicInfo);
        wx.navigateBack({
          delta: 0,
        })
    },
    /**
     * 生命周期函数--监听页面加载
     */
    onLoad: function (options) {
        var that = this;
        // wx.request({
        //   url: 'url',
        //   method:'GET',
        //   dataType:"json",
        //   responseType:'text',
        //   success:function (res) {
        //       that.setData({
        //         topicList:[
        //             {id:1,title:"春节买不到票",count:300},
        //             {id:2,title:"票太少",count:200},
        //             {id:3,title:"票价太贵",count:160},
        //         ]
        //       })
        //   },
        // })
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
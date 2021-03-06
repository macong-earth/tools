#include <string>

std::string result_min_css(
"  		body{padding:0;margin:0;font-size:14px;font-family:Arial,sans-serif;color:#434343;line-height:24px}\n"
"		h1,h2,h3,h4,h5,p,ul,form,li,ol,div,dl,dt,dd{margin:0;padding:0}\n"
"		ul,ol,li{list-style:none}\n"
"		a:link,a:visited{color:#35a1d4;outline:0}\n"
"		b{font-weight:normal;color:#638c0b}\n"
"		.additional{color:#959595}\n"
"		.sp,.result_navigator .go-top,.add_to_wordbook,.remove_from_wordbook,.desk-dict,.phone-dict,.wordbook,.yd-school,.sina,.netease,.tencent,.renren,.kaixin,.trans-wrapper h3 .toggleOpen,.trans-wrapper h3 .toggle,.more_sp,.more-collapse .more_sp,.video .close,.trans-container div .do-detail,.wt-collapse div .do-detail,.nav-collins .collins-icon,.sub-catalog .split,#editwordform #close-editwordform,.example_see_also .icon,.star{background:url(new-sprite.png) no-repeat;vertical-align:middle;overflow:hidden;display:inline-block}\n"
"		html{_background-image:url(null)}\n"
"		.sub-catalog li a:link,.sub-catalog li a:visited{color:#a0a0a0}\n"
"		.sub-catalog li a:hover,.example-group h3 a:hover{font-weight:bold;color:#434343}\n"
"		.result_navigator .go-top:hover{background-position:-59px 0}\n"
"		.result_navigator .back-to-dict:hover{border:2px solid #a9c7d7;color:#a9c7d7}\n"
"		.dict-inter a:hover{text-decoration:underline}\n"
"		.pr-link li a:hover,.follow .bd a{text-decoration:none;zoom:1}\n"
"		.pr-link li a:hover .desk-dict{background-position:-380px -31px}\n"
"		.pr-link li a:hover .phone-dict{background-position:-380px -171px}\n"
"		.pr-link li a:hover .wordbook{background-position:-379px -102px}\n"
"		.pr-link li a:hover .yd-school{background-position:-381px -244px}\n"
"		.follow a:hover .sina{background-position:-377px -283px}\n"
"		.follow a:hover .netease{background-position:-260px -285px}\n"
"		.follow a:hover .tencent{background-position:-41px -213px}\n"
"		.follow a:hover .renren{background-position:-152px -283px}\n"
"		.follow a:hover .kaixin{background-position:-35px -283px}\n"
"		.add-fav:hover{background-position:-168px -149px}\n"
"		.add-faved:hover{background-position:-209px -149px}\n"
"		#phrsListTab h2 .dictvoice:hover,#jcTrans h2 .dictvoice:hover{background-position:-92px 0;*background-position:-92px 3px}\n"
"		#jcTrans h2 .dictvoice:hover{background-position:-92px 5px;*background-position:-92px 3px}\n"
"		#phrsListTab h2 .baav .dictvoice:hover,#jcTrans h2 .baav .dictvoice:hover{background-position:-92px 3px;*background-position:-92px 0}\n"
"		#phrsListTab h2 .humanvoice:hover{background-position:-149px 4px}\n"
"		.dictvoice:hover{background-position:-32px -36px}\n"
"		.humanvoice:hover{background-position:-188px -110px}\n"
"		.add_to_wordbook:hover{background-position:-99px -30px;*background-position:-99px -32px}\n"
"		.remove_from_wordbook:hover{background-position:-205px 7px;*background-position:-205px 5px}\n"
"		.trans-wrapper h3 .toggle:hover{background-position:-202px -37px}\n"
"		.trans-wrapper h3 .toggleOpen:hover{background-position:-160px -37px}\n"
"		.results-content .tabs a:hover span{border-bottom:2px solid #5fc4f3}\n"
"		.trans-container{margin:.9em 0 1.8em}\n"
"		.trans-container p,.trans-container li{line-height:24px}\n"
"		.trans-container .ol{margin:8px 15px 0 20px;margin-left:33px}\n"
"		.trans-container .ol li{list-style:decimal;margin:0 0 .7em 0}\n"
"		p.via,span.via{color:#959595}\n"
"		#examples_sentences .allExplanation:hover{background:#a4d5ec}\n"
"		.phonetic,.field,.origin,.complexfont{font-weight:normal;color:#666;margin:0 .1em}\n"
"		.phonetic{color:#a0a0a0;font-family:\"lucida sans unicode\",arial,sans-serif}\n"
"		.wordGroup a.century21:hover{background:url(\"new-sprite.png\") no-repeat -110px -132px}\n"
"		.pr-container .title,.wt-container .title{font-weight:bold;position:relative}\n"
"		.trans-container div .do-detail:hover{background-position:-219px -74px}\n"
"		.wt-collapse div .do-detail:hover{background-position:-17px -74px}\n"
"		.wt-container a{outline:0}\n"
"		.more_sp:hover{background-position:-58px -74px}\n"
"		.more-collapse .more_sp:hover{background-position:-96px -74px}\n"
"		.example_content .content_title .boldWord a,.example_content .content_title .boldWord a:link,.example_content .content_title a:visited{text-decoration:none}\n"
"		.example_content .content_title .tabLink a:hover{color:#313131}\n"
"		.example_content a.allExplanation:hover{background-position:-85px -168px}\n"
"		.video .close:hover{background-position:-141px -72px}\n"
"		a.info:hover{background:#78c8e3}\n"
"		.example_see_also .info:hover .description,.example_see_also .info:hover .title{color:#fff}\n"
"		.trans-container .ensure,.trans-container a.ensure:hover{display:inline-block;width:61px;height:24px;cursor:pointer}\n"
"		.trans-container .ensure:hover{background-position:0 -237px}\n"
"		.trans-container .ensure:active{background-position:-122px -237px}\n"
"		.trans-container .cancel,.trans-container .cancel:hover{display:inline-block;width:61px;height:24px;margin-left:30px;cursor:pointer}\n"
"		.trans-container .cancel:hover{background-position:0 -261px}\n"
"		.trans-container .cancel:active{background-position:-122px -261px}\n"
"		.trans-content .pattern,.trans-content .spell{font-weight:normal;margin-left:5px;font-size:12px}\n"
"		.trans-content .pattern{margin-left:15px}\n"
"		.trans-content .title,.trans-content .rank{font-size:14px;color:#313131;font-weight:bold}\n"
"		.trans-content .rank{margin-left:10px}\n"
"		#collinsResult .ol{margin:8px 0 0 0}\n"
"		#collinsResult .ol li{list-style:none}\n"
"		#collinsResult .ol .collinsMajorTrans{background:#eff5f8;padding:5px 5px 5px 25px}\n"
"		#collinsResult .collinsOrder{float:left;margin-left:-15px}\n"
"		#collinsResult .exampleLists{margin:15px 0 15px 40px;color:#626262}\n"
"		.collinsMajorTrans .additional{color:#626262}\n"
"		#collinsResult .examples{padding-left:15px}\n"
"		#collinsResult b{font-weight:bold}\n"
"		.collinsToggle h4 .title{color:#eb6100}\n"
"		.star{margin-left:10px;background-position:-225px -112px;_background-position:-225px -110px;height:14px;vertical-align:middle}\n"
"		.star3{width:37px}\n"
"		.star2{width:25px}\n"
"		.star1{width:11px}\n"
"		.p-type:hover{color:#313131}\n"
"		.type-list a:hover{color:#434343}\n"
"		.all-trans .types .items a:link,.all-trans .types .items a:visited{font-size:12px;color:#959595;text-decoration:none}\n"
"		.all-trans .types .items a:hover{text-decoration:underline}\n"
"		.clearfix:after{content:\".\";display:block;height:0;visibility:hidden;clear:both}\n"
"		#langSelection a:hover{color:#000;background:#f5f5f5}\n"
"		#editwordform #close-editwordform:hover{background-position:-267px -32px}\n"
"		.phonetic{font-family:\"lucida sans unicode\",arial,sans-serif}\n"
"		.t0 .chromeWrap a:link,.t0 .chromeWrap a:visited{color:#046f9c;outline:0;text-decoration:none}\n"
"		.c-snav a:hover,.c-snav b{text-decoration:none;border-top:1px solid #d22e45}\n"
"		.c-snav .ne163:hover{border:0;text-decoration:underline}\n"
"		.c-sust a:hover{text-decoration:underline}\n"
"		#unameop a:hover{background:#f5f5f5;color:#000;text-decoration:none}\n"
"		.s-btn-w:hover{background-position:-176px 0}\n"
"		.s-btn-w:active{background-position:-88px 0}\n"
"		.c-fm-ext a:hover{text-decoration:underline}\n"
"		.c-bsearch .fblinks a:hover{text-decoration:underline}\n"
"		#c_footer a:hover{text-decoration:underline}\n"
"		#sidebar {\n"
"			height: 100%;\n"
"			padding: 2em;\n"
"			padding-left: 6em;\n"
"			border-right: 2px solid #999;\n"
"			position: fixed;\n"
"		}\n"
"		#sidebar img{\n"
"			padding-left: 5px;\n"
"		}\n"
"		#main {\n"
"			margin-left: 23em;\n"
"			position: relative;\n"
"		}\n"
"		#top-button {\n"
"			width: 100%;\n"
"			height: 50px;\n"
"			border: 1px solid #35A1D4;\n"
"			background-color: #1A506A;\n"
"			text-align: center;\n"
"			vertical-align: middle;\n"
"			position: fixed;\n"
"			bottom: 0;\n"
"			display: none;\n"
"		}\n"
"		@media only screen\n"
"		and (min-device-width : 320px)\n"
"		and (max-device-width : 480px) {\n"
"			#sidebar {\n"
"				padding: 2px;\n"
"				border: 0;\n"
"				line-height: 30px;\n"
"				font-size: 18px;\n"
"				position: static;\n"
"			}\n"
"			#main {\n"
"				margin-left: 2px;\n"
"			}\n"
"			h3 {\n"
"				display: inline;\n"
"				margin-right: 1em;\n"
"			}\n"
"			#top-button {\n"
"				display: block;\n"
"			}\n"
"		}\n"
);

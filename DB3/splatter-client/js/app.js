(function() { // We use this anonymous function to create a closure.

	var app = angular.module('splatter-web', ['ngResource', 'ngRoute']).
			config(function ($routeProvider) {
					$routeProvider.
						when('/index', {templateUrl: 'partials/splash.html'}).
						when('/register', {templateUrl: 'partials/Register.html'}).
						when('/home', {templateUrl: 'partials/Home.html'}).
						when('/profile', {templateUrl: 'partials/profile.html'}).
						otherwise({redirectTo: '/index'});
				})

	app.factory("User", function($resource) {
		return $resource( "http://glenn.sqrawler.com/api/users/:id.json", {id: '@id'} ,
								{ 
									'update': { method: 'PUT' },
									'getSpatts': {method: 'GET', url:"http://glenn.sqrawler.com/api/users/spatts/:id.json", isArray: true },
									'getSpattsFeed': {method: 'GET', url: "http://glenn.sqrawler.com/api/users/spatts-feed/:id.json", isArray: true },
									'followUser': { method: 'POST', url: "http://glenn.sqrawler.com/api/users/follows.json" } 
								});
	});		
	
	app.factory("Spatts", function($resource) {
		return $resource("http://glenn.sqrawler.com/api/spatts/:id.json", {id: '@id'} );
	});
	
	
	app.controller('UserController', function(User, Spatts, $scope, $location) {
		var id = -1;		
		this.ul = User.query();
		this.sl = User.getSpatts({id:-1});
		this.isLogedIn = false;
		this.sf = User.getSpattsFeed({id:1});
		
		this.postSpat = function(spatt) {
			spatter = new Spatts();
		    spatter.body = spatt.data["body"];
			spatter.user_id = this.loggedin_user.id;
			spatter.$save();
		
			this.getSpatFeed(this.loggedin_user);
		}
		
		this.getFollowers = function(id) {
			var x = 0;
		}
		
		this.followUser = function() {
			User.followUser({id:this.loggedin_user.id, follows_id: this.currentViewedUser.id});
		}		
		
		this.viewProfile = function() {
			this.sf = User.getSpattsFeed({id: this.currentViewedUser.id});
			$location.path("/profile");
		}
		
		// Home page
		this.getSpatFeed  = function(user) {
			var id ;
			if( user == -1) {
				id = user;
				this.currentViewedUser = null;
			}
			else {
				this.currentViewedUser = user;
				id = user.id;	
			}
			this.sl = User.getSpatts({id:id});	
		}
		
		// Registration 
		this.signup = function(user) {
			u = new User();
			u.name = this.data.cname;
			u.email = this.data.cemail;
			u.password = this.data.cpassword;
			u.blurb = this.data.cblurb;
			u.$save();

			$location.path( "/index" );
		};
		
		this.login = function() {
			var userName1 = this.data.name;
			var Password1 = this.data.password;

			$.ajax({
				url    :  "http://glenn.sqrawler.com/api/users/validate.json",	
				type :  "POST",
				data :  {
					username: userName1,
					password: Password1
				},
				dataType: "json",
				success : function(data)  {
					this.x = 0;
					$scope.user.setUser(data[0]['id']);
				}
			});
		};
		
		this.setUser = function(data) {
			this.loggedin_user = User.get({id:data});
			this.isLogedIn = true;
			$location.path( "/home" );
		};
		
	// add your user code above	
	});

})();
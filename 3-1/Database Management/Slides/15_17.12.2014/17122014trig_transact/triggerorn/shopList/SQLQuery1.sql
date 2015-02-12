USE [myTestDB]
GO

/****** Object:  Table [dbo].[ShoppingList]    Script Date: 15.12.2014 11:42:23 ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[ShoppingList](
	[ShopListID] [int] NOT NULL,
	[Item] [text] NULL,
	[quantity] [text] NULL,
	[LastModifiedDate] [smalldatetime] NULL,
 CONSTRAINT [PK_ShoppingList] PRIMARY KEY CLUSTERED 
(
	[ShopListID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO


